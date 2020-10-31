#include "classes.h"
#include <iostream>

int main() {
  School my_school(2, 9, 8, 9);
  Gymnasium my_gymnasium(3, 2, 9, 10, 9);

  Institute my_institute("Institute", 150);
  University my_university("BrSTU", "AI", 120);

  my_school.show();
  my_gymnasium.show();
  my_institute.show();
  my_university.show();

  std::cout << "general num of students method: "
            << my_university.general_num_of_students(
                   my_institute.get_students())
            << "\n\n";

  return 0;
}