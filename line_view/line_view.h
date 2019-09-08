class LineView {
public:
  LineView(FILE* file, size_t begin_position):
    file_(file), begin_position_(begin_position) {}

  uint8_t get_byte(size_t offset) {
    std::fseek(file_, begin_position + offset, SEEK_SET);
    uint8_t byte;
    std::read(&byte, sizeof(uint8_t), 1, file_);
    return byte;
  }

private:
  FILE* file_;
  size_t begin_position_;
};
