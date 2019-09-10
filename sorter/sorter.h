#include "temporary_file/temporary_file.h"
#include "line_view/line_view.h"
#include "file_with_lines/file_with_lines.h"

namespace {

std::optional<LineView> find_middle(
    std::optional<LineView> block_begin,
    std::optional<LineView> block_end
) {
  std::optional<LineView> middle = block_begin->copy();
  bool add_to_middle = true;
  std::clog << "middle: " << middle->begin_position() << ' ' ;
  while (
      block_begin != std::nullopt &&
      (
       !block_end.has_value() ||
       block_begin.value() != block_end.value()
      )
  ) {
    block_begin = block_begin->next();
    if (add_to_middle) {
      std::clog << "add_to_middle\n";
      middle = middle->next();
    }
    add_to_middle ^= 1;
  }
  std::clog << "final middle: " << middle->begin_position() << '\n' ;
  return middle;
}

void merge(
    std::optional<LineView> block_begin,
    std::optional<LineView> middle,
    std::optional<LineView> block_end
) {
  auto left_iterator = block_begin;
  auto right_iterator = middle;
  TemporaryFile temporary_file;
  while (
      left_iterator.value() != middle.value() ||
      (right_iterator.has_value() && right_iterator.value() != block_end.value())
  ) {
    while (
        left_iterator.has_value() &&
        !(right_iterator.has_value() && right_iterator.value() != block_end.value())
    ) {
      write_to_temporary_file(temporary_file, *left_iterator, block_begin.begin_position());
      left_iterator = left_iterator->next();
    }
    while (
        !left_iterator.has_value() &&
        (right_iterator.has_value() && right_iterator.value() != block_end.value())
    ) {
      write_to_temporary_file(temporary_file, *right_iterator, block_begin.begin_position());
      right_iterator = right_iterator->next();
    }
    if (
        left_iterator.has_value() && 
        (right_iterator.has_value() && right_iterator.value() != block_end.value())
    ) {
      if (left_iterator.value() < right_iterator.value()) {
        write_to_temporary_file(temporary_file, *left_iterator, block_begin.begin_position());
        left_iterator = left_iterator->next();
      } else {
        write_to_temporary_file(temporary_file, *right_iterator, block_begin.begin_position());
        right_iterator = right_iterator->next();
      }
    }
  }
}

void sort_block_with_lines(
    std::optional<LineView> block_begin,
    std::optional<LineView> block_end
) {
  std::clog << "block_begin position: " << block_begin->begin_position() << std::endl;
  if (block_end.has_value()) {
    std::clog << "block_end position: " << block_end->begin_position() << std::endl;
  }
  if (
      block_begin == std::nullopt ||
      (
        block_end.has_value() &&
        block_begin.value() == block_end.value()
      )
  ) {
    return;
  }

  auto next = block_begin->next();
  if (next.has_value()) {
    std::clog << "next: " << next->begin_position() << std::endl;
    if (
        block_end.has_value() &&
        next.value() == block_end.value()
    )
    {
      return;
    }
  }

  std::clog << "go to recursion" << std::endl;
  auto middle = find_middle(block_begin, block_end);
  std::clog << "middle: " << middle->begin_position() << std::endl;
  sort_block_with_lines(block_begin, middle);
  sort_block_with_lines(middle, block_end);

  merge(block_begin, middle, block_end);
}



}  // namespace

void sort_file_with_lines(FileWithLines file_with_lines) {
  sort_block_with_lines(file_with_lines.first_line(), std::nullopt);
}
