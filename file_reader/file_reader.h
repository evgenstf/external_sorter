class FileReader {
public:
  FileReader(const std::string& filename):
    input_stream_(filename) {}

private:
  std::ifstream input_stream_;
};
