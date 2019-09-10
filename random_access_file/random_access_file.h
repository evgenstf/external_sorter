#include <cstdio>
#include <string>
#include <vector>

class RandomAccessFile {
public:
  RandomAccessFile();
  RandomAccessFile(const std::string& filename);
  ~RandomAccessFile();

  uint8_t read(size_t position);
  std::vector<uint8_t> read(size_t position, size_t length);
  void write(size_t position, const std::vector<uint8_t>& data);

  FILE* file_;
};
