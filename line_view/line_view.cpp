#include "line_view.h"

namespace {

bool is_byte_exists(FILE* file, size_t offset) {
  std::fseek(file, offset, SEEK_SET);
  uint8_t byte;
  return std::fread(&byte, sizeof(uint8_t), 1, file) == 1;
}

} // namespace

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

std::optional<LineView> LineView::create(FILE* file, size_t begin_position) {
  if (is_byte_exists(file, begin_position)) {
    return LineView(file, begin_position);
  } else {
    return std::nullopt;
  }
}

std::optional<LineView> LineView::next() {
  return create(file_, begin_position_ + size() + 1);
}

std::optional<LineView> LineView::copy() {
  return create(file_, begin_position_);
}

