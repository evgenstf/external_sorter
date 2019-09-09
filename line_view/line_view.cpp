#include "line_view.h"
#include <cassert>

LineView::LineView(FILE* file, size_t begin_position, size_t length):
    file_(file), begin_position_(begin_position), length_(length) {}

uint8_t LineView::operator[](size_t offset) {
  std::fseek(file_, begin_position_ + offset, SEEK_SET);
  uint8_t byte;
  assert(std::fread(&byte, sizeof(uint8_t), 1, file_) == 1);
  return byte;
}

