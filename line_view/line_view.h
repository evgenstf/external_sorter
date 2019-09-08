#include <cstdio>
#include <optional>

class LineView {
public:
  static std::optional<LineView> create(FILE* file, size_t begin_position);

  std::optional<uint8_t> get_byte(size_t offset);
  size_t size() const { return size_; }

  std::optional<LineView> next();

private:
  LineView(FILE* file, size_t begin_position);

  FILE* file_;
  size_t begin_position_;
  size_t size_;
};
