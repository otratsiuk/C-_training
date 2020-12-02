#include "list.h"

int main() {

  //
  std::initializer_list<int> to_initialize = {1, 3,  7, 17, 182, 45, 76,
                                              8, 56, 2, 12, 54,  34, 76};

  List<int> my_list(to_initialize);

  my_list.display();

  std::cout << "element at position 4: " << my_list[3] << "\n";

  for (int i = 0; i < 3; i++) {
    my_list.push_front(0);
    my_list.push_back(0);
  }

  my_list.display();

  for (int i = 0; i < 3; i++) {
    my_list.pop_back();
    my_list.pop_front();
  }

  my_list.display();

  std::cout << my_list.size() << "\n";

  heap_sort(my_list, my_list.size());

  my_list.display();

  my_list.swap(my_list[0], my_list[13]);

  my_list.display();

  auto it = my_list.begin();

  it++;
  it++;
  it++;

  std::cout << *it << "\n";

  List<float> empty_list;

  try {
    empty_list.pop_back();

  } catch (List<float>::Is_empty) {
    std::cerr << "is_empty error\n";
  }

  try {
    my_list[55];
  } catch (List<int>::Out_of_range) {
    std::cerr << "out_of_range\n";
  }

  return 0;
}