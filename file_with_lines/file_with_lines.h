#include "random_access_file/random_access_file.h"
#include "file_with_lines/line_iterator.h"

class FileWithLines : public RandomAccessFile {
public:
  using RandomAccessFile::RandomAccessFile;

  LineIterator begin() const;
};
