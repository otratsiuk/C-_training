#include "shape.h"
#include <iomanip>
#include <iostream>
#include <vector>

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

  //
  Shape *shapes[5] = {new Circle(60), new Rectangle(45, 30), new Square(60),
                      new Circle(77), new Rectangle(50, 20)};

  double sum_square = 0;

  std::cout << "array of shapes: \n";
  for (int i = 0; i < 5; i++) {
    shapes[i]->draw(300, 200);

    std::cout << "square " << i << ": " << shapes[i]->square() << "\n";

    sum_square += shapes[i]->square();
  }

  std::cout << "general square for array of shapes: " << sum_square << "\n";

  return 0;
}