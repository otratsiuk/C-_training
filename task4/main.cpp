#include "university.h"
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  University my_uni("BrSTU", "Brest");
  my_uni.display();

  Faculty faculty("BSTU", "Minsk", 245, 2000);
  faculty.display();

  Course course("BrSTU", "Brest", 2, 1200);
  course.display();

  Group group;
  group.fill("BrSTU", "Brest", "Artificial Intelligence", 22);
  group.display();

  std::cout << "total value of students method:\n";
  std::cout << std::setw(15) << std::left << "faculties: " << std::setw(10)
            << std::right << faculty.total_value_of_students(5) << "\n"
            << std::setw(15) << std::left << "courses: " << std::setw(10)
            << std::right << course.total_value_of_students(4) << "\n"
            << std::setw(15) << std::left << "groups: " << std::setw(10)
            << std::right << group.total_value_of_students(2) << "\n";

  return 0;
}