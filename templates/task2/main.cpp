#include "array.h"
#include <initializer_list>
#include <iostream>

int main() {
  // using the template with int
  std::initializer_list<int> list_of_int = {1, 3, 5, 7, 9, 15};

  Array<int> array(list_of_int);

  std::cout << "\narray of int: ";
  array.show();

  std::cout << "mean of int array: " << array.method() << "\n";

  // using the template with char
  std::initializer_list<char> list_of_char = {'a', 'k', 'p'};

  Array<char> array_of_char(list_of_char);

  std::cout << "\narray of char: ";
  array_of_char.show();

  std::cout << "mean of char array: " << array_of_char.method() << "\n";

  // using the template with float
  std::initializer_list<float> list_of_float = {0.5, 1,   56,   9, 45,
                                                100, 3.5, 7.77, 9, 354};

  Array<float> array_of_float(list_of_float);

  std::cout << "\narray of char: ";
  array_of_float.show();

  std::cout << "mean of float array: " << array_of_float.method() << "\n\n";
  return 0;
}