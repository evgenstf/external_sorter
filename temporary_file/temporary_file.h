#include "random_access_file/random_access_file.h"
#include <cstdlib>

class TemporaryFile : public RandomAccessFile {
public:
  TemporaryFile():
      RandomAccessFile(std::tmpfile()) {}
};
