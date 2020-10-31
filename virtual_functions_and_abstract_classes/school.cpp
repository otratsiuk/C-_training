#include "classes.h"
#include <iomanip>
#include <iostream>

School::School() : Secondary_education(){};

School::School(int num, int maths, int language, int physics)
    : Secondary_education(num, maths, language, physics){};

float School::average_points() {
  return (
      static_cast<float>(maths_average + language_average + physics_average) /
      3);
}

void School::show() {
  std::cout << std::setw(30) << std::left << "school №" << std::setw(30)
            << std::right << number << std::setw(30) << std::left
            << "\naverage points: " << std::setw(30) << std::right
            << average_points() << "\n\n";
};