#ifndef _MY_STRING_H
#define _MY_STRING_H

#include <iostream>

class String {
private:
  char *str;
  std::size_t length;

public:
  String(const char *const s);

  explicit String(String &&other);

  String(const String &other);

  ~String();

  void display();
};

//#include "my_string.cpp"

#endif