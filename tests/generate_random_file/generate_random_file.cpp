#include "generate_random_file.h"

#include <fstream>
#include <iostream>

namespace {

char generate_random_char() {
  return 'a' + rand() % 26;
}

}  // namespace

void generate_random_file(
    const std::string& filename,
    uint32_t line_count,
    uint32_t max_line_size
) {
  std::ofstream output_stream(filename);
  for (uint32_t line_index = 0; line_index < line_count; ++line_index) {
    uint32_t line_length = rand() % (max_line_size + 1);
    for (uint32_t char_index = 0; char_index < line_length; ++char_index) {
      output_stream << generate_random_char();
    }
    output_stream << '\n';
  }
}
