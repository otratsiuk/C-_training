#include "classes.h"
#include <iomanip>
#include <iostream>
#include <string>

University::University() : Higher_education(), specialization("unknown"){};

University::University(const std::string &name, const std::string &spec,
                       int num)
    : Higher_education(name, num), specialization(spec){};

int University::get_students() { return num_of_students; };

int University::general_num_of_students(int num) {
  return num_of_students + num;
}

void University::show() {
  std::cout << std::setw(30) << std::left << "University name:" << std::setw(30)
            << std::right << name << std::setw(30) << std::left
            << "\nnumber of students: " << std::setw(30) << std::right
            << num_of_students << "\n\n";
};
