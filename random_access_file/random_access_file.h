#include <cstdio>
#include <string>
#include <vector>

class RandomAccessFile {
public:
  RandomAccessFile(const std::string& filename);
  ~RandomAccessFile();

  std::vector<uint8_t> read(size_t position, size_t length);
  void write(size_t position, const std::vector<uint8_t>& data);

protected:
  RandomAccessFile(FILE* file);

private:
  FILE* file_;
};
