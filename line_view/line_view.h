#pragma once
#include <cstdio>
#include <cstdint>

class LineView {
public:
  LineView(FILE* file, size_t begin_position, size_t length);

  uint8_t operator[](size_t offset);
  size_t length() const { return length_; }

  bool operator==(const LineView& right) const {
    return right.begin_position_ == begin_position_;
  }

  bool operator!=(const LineView& right) const {
    return right.begin_position_ != begin_position_;
  }

  size_t begin_position() const { return begin_position_; }

private:
  FILE* file_;
  size_t begin_position_;
  size_t length_;
};
