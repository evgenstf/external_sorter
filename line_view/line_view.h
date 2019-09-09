#pragma once
#include <cstdio>
#include <optional>

class LineView {
public:
  static std::optional<LineView> create(FILE* file, size_t begin_position);

  std::optional<uint8_t> get_byte(size_t offset);
  size_t size() const { return size_; }

  std::optional<LineView> next();
  std::optional<LineView> copy();

  bool operator==(const LineView& right) const {
    return right.begin_position_ == begin_position_;
  }

  bool operator!=(const LineView& right) const {
    return right.begin_position_ != begin_position_;
  }

  size_t begin_position() const { return begin_position_; }

private:
  LineView(FILE* file, size_t begin_position);

  FILE* file_;
  size_t begin_position_;
  size_t size_;
};
