#include "temporary_file.h"
#include <iostream>

int main() {
  TemporaryFile file;
  std::vector<uint8_t> data{'a', 'b', 'c'};
  file.write(3, data);

  auto result = file.read(0, 10);
  std::clog << "write and read string: ";
  for (auto c : result) {
    std::clog << '"' << c << '"' << ' ';
  }
  std::clog << std::endl;
  return 0;
}
