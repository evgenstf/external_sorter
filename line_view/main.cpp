#include "line_view.h"
#include <iostream>

int main() {
  FILE* file = std::fopen("text.txt", "r+");
  if (file) {
    LineView line(file, 1, 3);
    std::clog << "read line: ";
    for (size_t index = 0; index < line.length(); ++index) {
      std::clog << '"' << line[index] << '"' << ' ';
    }
    std::clog << std::endl;
  } else {
    std::clog << "file not exists" << std::endl;
  }
  return 0;
}
