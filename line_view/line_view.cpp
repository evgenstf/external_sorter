#include "line_view.h"
#include <cassert>

LineView::LineView(const RandomAccessFile& file, size_t begin_position, size_t length):
    file_(file), begin_position_(begin_position), length_(length) {}

uint8_t LineView::operator[](size_t offset) const {
  auto read_byte = file_.read(begin_position_ + offset);
  assert(read_byte.has_value());
  return read_byte.value();
}

