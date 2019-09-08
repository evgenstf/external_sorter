class Line {
public:
  Line(FileReaderIterator file_reader_iterator):
    file_reader_iterator_(std::move(file_reader_iterator)) {}

  std::string load() {
    std::string line;   
    uint32_t char_index = 0;
    for (
        auto current_char = file_reader_iterator_.peek(char_index);
        current_char.has_value() && current_char.value() != '\n';
        ++char_index
    ) {
      line.push_back(current_char.value());
    }
    return line;
  }

private:
  FileReaderIterator file_reader_iterator_;
};
