#include "shape.h"
#include <iomanip>
#include <iostream>

int main() {

  Circle circle(100.65);

  std::cout << std::left << std::setw(40) << "circle square: " << std::setw(15)
            << circle.square() << "\n";
  std::cout << std::left << std::setw(40)
            << "circle perimeter: " << std::setw(15) << circle.perimeter()
            << "\n\n";

  Rectangle rectangle(140, 46);

  std::cout << std::left << std::setw(40)
            << "rectangle square: " << std::setw(15) << rectangle.square()
            << "\n";
  std::cout << std::left << std::setw(40)
            << "rectangle perimeter: " << std::setw(15) << rectangle.perimeter()
            << "\n\n";

  Square square(40);

  std::cout << std::left << std::setw(40) << "square square: " << std::setw(15)
            << square.square() << "\n";
  std::cout << std::left << std::setw(40)
            << "square perimeter: " << std::setw(15) << square.perimeter()
            << "\n\n";

  circle.draw(100, 300);

  rectangle.draw(200, 50);

  square.draw(300, 250);

  return 0;
}