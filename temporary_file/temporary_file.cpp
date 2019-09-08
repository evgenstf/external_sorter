#include "temporary_file.h"

#include <cstdlib>

TemporaryFile::TemporaryFile() {
  file_ = std::tmpfile();
}

TemporaryFile::~TemporaryFile() {
  std::fclose(file_);
}

void TemporaryFile::write(size_t position, const std::vector<uint8_t>& data) {
  std::fseek(file_, position, SEEK_SET);
  std::fwrite(data.data(), sizeof(uint8_t), data.size(), file_);
}

std::vector<uint8_t> TemporaryFile::read(size_t position, size_t length) {
  std::vector<uint8_t> data(length);
  std::fseek(file_, position, SEEK_SET);
  std::fread(data.data(), sizeof(uint8_t), length, file_);
  return data;
}

