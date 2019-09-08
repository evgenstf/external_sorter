#include "line_view.h"

LineView::LineView(FILE* file, size_t begin_position):
    file_(file), begin_position_(begin_position), size_(0) {
  auto current_byte = get_byte(size_);
  while (current_byte.has_value() && *current_byte != '\n') {
    ++size_;
    current_byte = get_byte(size_);
  }
}

std::optional<uint8_t> LineView::get_byte(size_t offset) {
  std::fseek(file_, begin_position_ + offset, SEEK_SET);
  uint8_t byte;
  if (std::fread(&byte, sizeof(uint8_t), 1, file_) != 1) {
    return std::nullopt;
  }
  return byte;
}
