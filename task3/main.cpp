#include "vector.h"
#include <iomanip>
#include <iostream>

int main() {
  Vector vector1;
  Vector vector2(10);

  vector1.fill_vector();
  vector2.fill_vector();

  std::cout << "\nearly vector1:\t\t";
  vector1.show_vector();

  vector1.sort_in_descending_order();
  std::cout << "\nsorted vector1:\t\t";
  vector1.show_vector();

  std::cout << "\nmin of vector1:\t\t" << vector1.find_min_value();
  std::cout << "\nmax of vector1:\t\t" << vector1.find_max_value();
  std::cout << "\naverage of vector1:\t" << vector1.find_average_value();

  std::cout << "\n\nearly vector2:\t\t";
  vector2.show_vector();

  vector2.method();
  std::cout << "\nmethod for vector2:\t";
  vector2.show_vector();
  std::cout << "\n";

  return 0;
}