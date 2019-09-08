#include "file_reader/file_reader.h"

class LinesManager {
public:
  LinesManager(FileReader file_reader):
    file_reader_(std::move(file_reader)) {}


private:
  FileReader file_reader_;
};
