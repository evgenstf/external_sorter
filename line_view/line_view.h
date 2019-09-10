#pragma once
#include "random_access_file/random_access_file.h"
#include <cstdio>
#include <cstdint>

class LineView {
public:
  LineView(const RandomAccessFile& file, size_t begin_position, size_t length);

  size_t length() const { return length_; }
  size_t begin_position() const { return begin_position_; }

  void set_length(size_t length) { length_ = length; }
  void set_begin_position(size_t begin_position) { begin_position_ = begin_position; }

  uint8_t operator[](size_t offset) const;

private:
  const RandomAccessFile& file_;
  size_t begin_position_;
  size_t length_;
};
