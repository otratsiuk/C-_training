#include "dofile.h"

Dofile::File_exception::File_exception(std::string error_name)
    : error(error_name) {}

const char *Dofile::File_exception::what() const noexcept {
  return error.c_str();
}

Dofile::Dofile(std::string file_name) : name(file_name) {
  file.open(name);
  if (!file.is_open()) {
    throw File_exception("no file with such name");
  }
}

void Dofile::display() {
  if (!file.is_open()) {
    throw File_exception("file is closed");
  }

  file.seekg(0, file.end);
  if (file.tellg() <= 0) {
    throw(File_exception("Empty file"));
  }

  file.seekg(0, file.beg);

  std::string line;

  std::cout << "\n";
  while (getline(file, line)) {
    std::cout << line << "\n";
  }
  std::cout << "\n";

  file.clear();
  file.seekg(0, file.beg);
}

void Dofile::write(std::string &line) {
  if (!file.is_open()) {
    throw File_exception("file is closed");
  }

  file.seekg(0, file.end);

  file << line << "\n";
}