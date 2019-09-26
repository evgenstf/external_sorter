#include "sort.h"
#include "file_with_lines.h"
#include "line_iterator.h"

#include <vector>

#include <iostream>

namespace {

void print_file(const FileWithLines& file, size_t begin_position = 0) {
  LineIterator iterator(file, begin_position);
  while (!iterator.is_last()) {
    std::clog << '"';
    for (size_t i = 0; i < iterator.line_view().length(); ++i) {
      std::clog << iterator.line_view()[i];
    }
    std::clog << '"';
    std::clog << ' ';
    ++iterator;
  }
  std::clog << std::endl;
}

void merge(FileWithLines& file, size_t begin, size_t middle, size_t end) {
  LineIterator left(file, begin);
  LineIterator right(file, middle);
  FileWithLines tmp;
  while (
      left.line_view().begin_position() < middle ||
      right.line_view().begin_position() < end
  ) {
    while (
      left.line_view().begin_position() >= middle &&
      right.line_view().begin_position() < end
    ) {
      tmp.push_back(right.line_view());
      ++right;
    }
    while (
      left.line_view().begin_position() < middle &&
      right.line_view().begin_position() >= end
    ) {
      tmp.push_back(left.line_view());
      ++left;
    }
    while (
        left.line_view().begin_position() < middle &&
        right.line_view().begin_position() < end
    ) {
      if (left.line_view() < right.line_view()) {
        tmp.push_back(left.line_view());
        ++left;
      } else {
        tmp.push_back(right.line_view());
        ++right;
      }
    }
  }

  for (size_t i = 0; i < tmp.size(); ++i) {
    file.write(begin + i, std::vector<uint8_t>({tmp.read(i).value()}));
  }
}

void recursive_sort(FileWithLines& file, size_t begin, size_t end) {
  LineIterator iterator(file, begin);
  ++iterator;
  auto middle = iterator.line_view().begin_position();
  if (middle == end) {
    return;
  }
  middle = (begin + end) / 2;
  while (middle > begin && file.read(middle) != '\n') {
    --middle;
  }
  if (middle == begin) {
    middle = iterator.line_view().begin_position();
  } else {
    ++middle;
  }

  recursive_sort(file, begin, middle);
  recursive_sort(file, middle, end);
  merge(file, begin, middle, end);
}

}  // namespace

void sort(FileWithLines& file) {
  recursive_sort(file, 0, file.size());
}
