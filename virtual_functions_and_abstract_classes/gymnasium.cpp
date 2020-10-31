#include "classes.h"
#include <iomanip>
#include <iostream>
#include <string>

Gymnasium::Gymnasium() : Secondary_education(), num_of_grades(0){};

Gymnasium::Gymnasium(int num, int grades, int maths, int language, int physics)
    : Secondary_education(num, maths, language, physics),
      num_of_grades(grades){};

float Gymnasium::average_points() {
  return (
      static_cast<float>(maths_average + language_average + physics_average) /
      3);
}

void Gymnasium::show() {
  std::cout << std::setw(30) << std::left << "Gymnasium №" << std::setw(30)
            << std::right << number << std::setw(30) << std::left
            << "\nNumber of grades:" << std::setw(30) << std::right
            << num_of_grades << std::setw(30) << std::left
            << "\naverage points: " << std::setw(30) << std::right
            << average_points() << "\n\n";
};