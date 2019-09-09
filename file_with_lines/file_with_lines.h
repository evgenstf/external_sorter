#include "line_view/line_view.h"
#include <stdexcept>
#include <string>

class FileWithLines {
public:
  FileWithLines(const std::string& filename) {
    file_ = std::fopen(filename.c_str(), "r+");
    if (!file_) {
      throw std::invalid_argument("file does not exists");
    }
  }

  ~FileWithLines() {
    std::fclose(file_);
  }

  std::optional<LineView> first_line() {
    return LineView::create(file_, 0);
  }

private:
  FILE* file_;
};
