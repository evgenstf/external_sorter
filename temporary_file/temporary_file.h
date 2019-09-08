#include <cstdio>
#include <vector>

class TemporaryFile {
public:
  TemporaryFile();
  ~TemporaryFile();

  void write(size_t position, std::vector<uint8_t> data);
  std::vector<uint8_t> read(size_t position, size_t length);

private:
  FILE* file_;
};
