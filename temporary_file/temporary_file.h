#include <cstdio>
#include <vector>

class TemporaryFile {
public:
  TemporaryFile();
  ~TemporaryFile();

  std::vector<uint8_t> read(size_t position, size_t length);

  template<typename Iterator>
  void write(size_t position, Iterator begin, Iterator end);
  void write(size_t position, const std::vector<uint8_t>& data);


private:
  FILE* file_;
};

template<typename Iterator>
void TemporaryFile::write(size_t position, Iterator begin, Iterator end) {
  std::vector<uint8_t> data;
  while(begin != end) {
    data.push_back(*begin);
    ++begin;
  }
  write(position, data);
}
