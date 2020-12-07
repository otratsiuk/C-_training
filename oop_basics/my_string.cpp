#include "my_string.h"
#include <cstring>

String::String(const char *const s) {
  length = std::strlen(s) + 1;
  str = new char[length];
  std::strcpy(str, s);

  std::cout << "constructor String(const char *const s)\n";
}

String::String(String &&other) {
  length = other.length;
  str = new char[length];
  std::strcpy(str, other.str);

  other.length = 0;
  other.str = nullptr;

  std::cout << "constructor String(String &&other)\n";
}

String ::String(const String &other) {
  length = other.length + 1;
  str = new char[length];
  std::strcpy(str, other.str);

  std::cout << "constructor String(const String &other)\n";
}

String::~String() {
  delete[] str;
  std::cout << "destructor ~String()\n";
}

void String::display() {
  for (int i = 0; i < length; i++) {
    std::cout << str[i];
  }
  std::cout << "\n";
}