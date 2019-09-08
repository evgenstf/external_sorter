#include <cstdio>
#include <optional>

class LineView {
public:
  LineView(FILE* file, size_t begin_position);
  std::optional<uint8_t> get_byte(size_t offset);
  size_t size() const { return size_; }

private:
  FILE* file_;
  size_t begin_position_;
  size_t size_;
};
