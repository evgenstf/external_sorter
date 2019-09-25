#include "line_view.h"

#include <algorithm>
#include <iostream>
#include <vector>

void print_line(const LineView& line) {
  for (size_t index = 0; index < line.length(); ++index) {
    std::clog << '"' << line[index] << '"' << ' ';
  }
  std::clog << std::endl;
}

int main() {
  RandomAccessFile file("text.txt");
  std::vector<LineView> lines{
    LineView(file, 1, 3),
    LineView(file, 5, 3),
    LineView(file, 9, 2)
  };
  for (int i = 0; i < lines.size() - 1; ++i) {
    print_line(lines[i]);
    std::clog << (lines[i] < lines[i + 1] ? "<" : "!<") << std::endl;
  }
  print_line(lines.back());
  return 0;
}
