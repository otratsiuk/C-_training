#include <iomanip>
#include <iostream>
#include <string>

std::string find_max(std::string &a, std::string &b) {
  return a.length() > b.length() ? a : b;
}

template <typename T> T find_max(T a, T b) { return a > b ? a : b; }

template <typename T, int length> T find_max(const T (&array)[length]) {
  T max = array[0];

  for (int i = 1; i < length; i++) {
    max = find_max(max, array[i]);
  }
  return max;
}

int main() {
  std::cout << std::setw(20) << std::left
            << "max number: " << find_max(-3.4, 10.0) << "\n";

  int array[7] = {3, -4, 9, -23, 182, -4, 1};

  std::cout << std::setw(20) << std::left
            << "max array number: " << find_max(array) << "\n";

  std::string a("Cat");
  std::string b("CatDog");
  std::cout << std::setw(20) << std::left
            << "the longest string: " << find_max(a, b) << "\n";

  return 0;
}