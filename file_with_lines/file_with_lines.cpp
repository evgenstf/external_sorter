#include "file_with_lines.h"

LineIterator FileWithLines::begin() const {
  return LineIterator(*this, 0);
}
