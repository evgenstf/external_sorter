#include "random_access_file.h"

#include <cstdlib>

RandomAccessFile::RandomAccessFile(const std::string& filename) {
  file_ = std::fopen(filename.c_str(), "r+");
}

RandomAccessFile::RandomAccessFile(FILE* file):
    file_(file) {}

RandomAccessFile::~RandomAccessFile() {
  std::fclose(file_);
}

void RandomAccessFile::write(size_t position, const std::vector<uint8_t>& data) {
  std::fseek(file_, position, SEEK_SET);
  std::fwrite(data.data(), sizeof(uint8_t), data.size(), file_);
}

std::vector<uint8_t> RandomAccessFile::read(size_t position, size_t length) {
  std::vector<uint8_t> data(length);
  std::fseek(file_, position, SEEK_SET);
  std::fread(data.data(), sizeof(uint8_t), length, file_);
  return data;
}

