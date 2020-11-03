#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  // Task1

  // 1)
  auto display_lambda = [](int element) { std::cout << element << " "; };

  std::vector<int> my_vector{5, 1, 10, 2, 4, 7};

  std::for_each(my_vector.begin(), my_vector.end(), display_lambda);
  std::cout << "\n";

  // 2)
  int count = 0;
  auto count_lambda = [&](int a, int b) {
    count++;
    return 0;
  };

  std::sort(my_vector.begin(), my_vector.end(), count_lambda);

  std::cout << "number of rearrangements: " << count << "\n";

  // 3)
  std::string my_string("CatzzzzzzzzzzDog");
  std::string my_substr("Dog");

  std::size_t pos;
  auto index_of = [&](std::string string, std::string substr) {
    return pos = string.find(substr);
  };

  std::cout << "substr found at: " << index_of(my_string, my_substr) << "\n";

  return 0;
}
