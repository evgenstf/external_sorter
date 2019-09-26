#include "file_with_lines.h"
#include "line_iterator.h"
#include "sort.h"
#include <iostream>

int main() {
  {
    FileWithLines file_to_read("text.txt");
    FileWithLines file_to_write("output.txt");
    auto iterator = file_to_read.begin();
    while (!iterator.is_last()) {
      file_to_write.push_back(iterator.line_view());
      for (size_t i = 0; i < iterator.line_view().length(); ++i) {
        std::clog << '"' << iterator.line_view()[i] << '"' << ' ';
      }
      std::clog << std::endl;
      ++iterator;
    }
  }

  FileWithLines file_to_sort("output.txt");
  sort(file_to_sort);
  return 0;
}
