#pragma once

#include "line_view/line_view.h"
#include "random_access_file/random_access_file.h"

class LineIterator {
public:
  LineIterator(const RandomAccessFile& file, size_t begin_position);

  const LineView line_view() const { return line_; }

  LineIterator& operator++();
  bool is_last() const;

  bool operator==(const LineIterator& right) const;

private:
  const RandomAccessFile& file_;
  LineView line_;
};
