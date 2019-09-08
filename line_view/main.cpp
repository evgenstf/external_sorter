#include "line_view.h"
#include <iostream>

int main() {
  FILE* file = std::fopen("text.txt", "r+");
  if (file) {
    auto line = LineView::create(file, 0);
    while (line.has_value()) {
      std::clog << "read line size: " << line->size() << std::endl;
      std::clog << "data: ";
      for (size_t i = 0; i < line->size(); ++i) {
        std::clog << '"' << (*line->get_byte(i)) << '"' << ' ';
      }
      std::clog << std::endl;
      line = line->next();
    }
  } else {
    std::clog << "file not exists" << std::endl;
  }
  return 0;
}
