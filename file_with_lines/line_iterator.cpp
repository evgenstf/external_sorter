#include "line_iterator.h"
#include "line_view/line_view.h"
#include <utility>

namespace {

size_t calculate_length_of_line(const RandomAccessFile& file, size_t begin_position) {
  auto read_byte = file.read(begin_position);
  size_t length = 0;
  while (read_byte.has_value() && read_byte.value() != '\n') {
    ++length;
    read_byte = file.read(begin_position + length);
  }
  return length;
}

}  // namespace

LineIterator::LineIterator(const RandomAccessFile& file, size_t begin_position):
    file_(file), line_(file_, begin_position, calculate_length_of_line(file_, begin_position)) {}

LineIterator& LineIterator::operator++() {
  size_t next_begin_position = line_.begin_position() + line_.length() + 1;
  line_.set_begin_position(next_begin_position);
  line_.set_length(calculate_length_of_line(file_, next_begin_position));
  return *this;
}

bool LineIterator::is_last() const {
  return !file_.read(line_.begin_position()).has_value();
}
