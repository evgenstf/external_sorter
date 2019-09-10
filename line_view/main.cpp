#include "line_view.h"
#include <iostream>

int main() {
  RandomAccessFile file("text.txt");
  LineView line(file, 1, 3);
  std::clog << "read line: ";
  for (size_t index = 0; index < line.length(); ++index) {
    std::clog << '"' << line[index] << '"' << ' ';
  }
  std::clog << std::endl;
  return 0;
}
