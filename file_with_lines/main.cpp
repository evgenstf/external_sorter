#include "file_with_lines.h"
#include "line_iterator.h"
#include <iostream>

int main() {
  FileWithLines file("text.txt");
  auto iterator = file.begin();
  while (iterator.line_view().length() != 0) {
    for (size_t i = 0; i < iterator.line_view().length(); ++i) {
      std::clog << '"' << iterator.line_view()[i] << '"' << ' ';
    }
    std::clog << std::endl;
    ++iterator;
  }
  return 0;
}
