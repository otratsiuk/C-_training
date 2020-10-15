#include <initializer_list>
#include <iomanip>
#include <iostream>

class Array {
public:
  int **array;
  int r;
  int c;

public:
  Array(const std::initializer_list<std::initializer_list<int>> &list) {
    r = list.size();
    for (auto &row : list) {
      c = row.size();
      break;
    }

    array = new int *[r];
    for (int i = 0; i < r; i++) {
      array[i] = new int[c];
    }

    int i = 0;
    int j = 0;
    for (auto &rows : list) {
      for (auto &element : rows) {
        array[i][j] = element;
        ++j;
      }
      j = 0;
      ++i;
    }
  }

  ~Array() {
    for (int i = 0; i < r; i++) {
      delete[] array[i];
    }

    delete[] array;
  }

  void display() {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        std::cout << std::setw(4) << std::right << array[i][j];
      }
      std::cout << "\n";
    }
  }

  friend int sum_of_columns(Array array);
};

int sum_of_columns(Array array) {
  bool contains_positive = false;
  bool is_solution = false;

  int general_sum = 0;
  int column_sum = 0;

  for (int i = 0; i < array.c; i++) {
    for (int j = 0; j < array.r; j++) {

      if (array.array[j][i] >= 0) {
        contains_positive = true;
      }

      column_sum += array.array[j][i];
    }

    if (contains_positive) {
      is_solution = true;

      general_sum += column_sum;

      column_sum = 0;
      contains_positive = false;
    } else {
      column_sum = 0;
    }
  }

  if (!is_solution) {
    std::cout << "\nno solution: ";
    return 0;
  } else {
    return general_sum;
  }
}

int main() {
  std::initializer_list<std::initializer_list<int>> my_list = {
      {-1, -1, -1}, {-2, -1, -1}, {-3, -1, -1}};

  Array array(my_list);

  array.display();

  std::cout << "method: " << sum_of_columns(array) << "\n";

  return 0;
}