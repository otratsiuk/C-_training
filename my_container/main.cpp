#include "list.h"

int main() {
  std::initializer_list<int> to_initialize = {1, 2, 3, 4, 5, 6, 7};

  List<int> my_list(to_initialize);

  my_list.display();

  my_list.push_front(9);

  my_list.display();

  my_list.pop_back();
  my_list.pop_back();
  my_list.pop_back();
  my_list.pop_front();
  my_list.pop_front();
  my_list.pop_front();

  my_list.display();

  return 0;
}