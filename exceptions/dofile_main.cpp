#include "dofile.h"

int main() {

  try {
    std::string bad_file = "fileee";
    Dofile file(bad_file);
  } catch (Dofile::File_exception &exception) {
    std::cerr << "file exception occured: " << exception.what() << "\n";
  }

  std::string empty_file = "./exceptions/empty.txt";

  try {
    Dofile file(empty_file);

    file.display();

  } catch (Dofile::File_exception &exception) {
    std::cerr << "file exception occured: " << exception.what() << "\n";
  }

  try {
    Dofile file("./exceptions/file.txt");
    file.display();

    std::string author = "Frank Sinatra";
    file.write(author);

    file.display();
  } catch (Dofile::File_exception &exception) {
    std::cerr << "file exception occured: " << exception.what() << "\n";
  }

  return 0;
}