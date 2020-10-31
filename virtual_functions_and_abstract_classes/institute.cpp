#include "classes.h"
#include <iomanip>
#include <iostream>
#include <string>

Institute::Institute() : Higher_education(){};

Institute::Institute(const std::string &name, int num)
    : Higher_education(name, num){};

int Institute::get_students() { return num_of_students; };

int Institute::general_num_of_students(int num) {
  return num_of_students + num;
}

void Institute::show() {
  std::cout << std::setw(30) << std::left << "Institute name:" << std::setw(30)
            << std::right << name << std::setw(30) << std::left
            << "\nnumber of students: " << std::setw(30) << std::right
            << num_of_students << "\n\n";
};