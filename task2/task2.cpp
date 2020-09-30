#include <algorithm>
#include <iostream>
#include <string>

void reverse_string(std::string &input_string) {
  int swap_times = input_string.size();

  for (int i = 0; i <= swap_times; i++) {
    std::swap(input_string[i], input_string[input_string.size() - i]);
  }
}

class String {
private:
  std::string str;

public:
  String(const std::string &input_string) : str(input_string) {}

  ~String() { str.clear(); }

  void print_string() { std::cout << str << "\n"; }

  void function() {
    if (str.find('!') != std::string::npos) {
      for (int i = 0; i < str.size(); i++) {
        if (str[i] == '!') {
          str[i] = '?';
        }
      }
    } else if (str.find('!') == std::string::npos) {
      reverse_string(str);
    }
  }
};

int main() {
  String string1("baby!yoda!");
  String string2("yabbadabba");

  std::cout << "\noriginal string1: ";
  string1.print_string();
  std::cout << "original string2: ";
  string2.print_string();

  string1.function();
  string2.function();

  std::cout << "\nchanged string1: ";
  string1.print_string();
  std::cout << "changed string2: ";
  string2.print_string();
  std::cout << "\n";

  return 0;
}