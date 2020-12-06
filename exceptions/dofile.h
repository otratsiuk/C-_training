#ifndef _DOFILE_H
#define _DOFILE_H

#include <exception>
#include <fstream>
#include <iostream>

class Dofile {
private:
  std::string name;
  std::fstream file;

public:
  class File_exception : public std::exception {
  private:
    std::string error;

  public:
    File_exception(std::string error_name);

    const char *what() const noexcept;
  };

  Dofile(std::string file_name);

  void display();

  void write(std::string &line);
};

#include "dofile.cpp"

#endif