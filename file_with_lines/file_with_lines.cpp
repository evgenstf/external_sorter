#include "file_with_lines.h"

#include <vector>

namespace {

const size_t kBufferSize = 1000;

};  // namespace

LineIterator FileWithLines::begin() const {
  return LineIterator(*this, 0);
}

void FileWithLines::push_back(const LineView& line_view) {
  std::vector<uint8_t> buffer;
  buffer.reserve(kBufferSize);

  for (size_t i = 0; i < line_view.length(); ++i) {
    if (buffer.size() < kBufferSize) {
      buffer.push_back(line_view[i]);
    } else {
      write_back(buffer);
      buffer.clear();
    }
  }
  write_back(buffer);
  write_back({'\n'});
}
