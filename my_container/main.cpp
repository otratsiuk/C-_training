#include "list.h"

int main() {
  std::initializer_list<int> to_initialize = {12, 25, 3, -4,  5,  76,  57, 10,
                                              5,  2,  0, 182, 34, 156, 3};

  List<int> my_list(to_initialize);

  my_list.display();

  std::cout << my_list[3] << "\n";

  heap_sort(my_list, my_list.size());

  my_list.display();

  List<int>::Iterator it = my_list.begin();

  it++;
  it++;
  it++;

  std::cout << *it << "\n";

  List<int>::Iterator it_end = my_list.end();

  std::cout << *it_end << "\n";

  return 0;
}