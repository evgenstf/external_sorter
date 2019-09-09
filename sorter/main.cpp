#include "sorter.h"
#include <iostream>

int main() {
  FileWithLines file_with_lines("text.txt");
  sort_file_with_lines(std::move(file_with_lines));
}
