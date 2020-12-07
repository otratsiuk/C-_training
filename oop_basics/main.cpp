#include "my_string.h"
#include <iostream>

int main() {

  String my_string("helloworld");
  my_string.display();
  std::cout << "\n";

  String to_move_to(std::move(my_string));
  to_move_to.display();
  std::cout << "\n";

  String to_copy_to(to_move_to);
  to_copy_to.display();
  std::cout << "\n";
  return 0;
}