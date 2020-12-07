#include "employee.h"
#include "iostream"

size_t max_int(int *arr, size_t size) {
  auto max = 0;
  for (int i = 1; i < size; i++) {
    if (arr[i] > arr[max]) {
      max = i;
    }
  }
  return max;
}

int main() {
  // Task1
  std::cout << "\nTask1\n";

  Employee employees[100];

  int number;
  std::cout << "enter number of employees: ";
  std::cin >> number;

  for (int i = 0; i < number; i++) {
    Employee employee;
    employee.get_data();
    employees[i] = employee;
  }

  for (int i = 0; i < number; i++) {
    employees[i].put_data();
  }

  // Task2
  std::cout << "\nTask2\n";

  size_t size;
  std::cout << "enter size of array: ";
  std::cin >> size;

  int *array = new int[size];

  std::cout << "Enter array elements(int): ";
  for (int i = 0; i < size; i++) {
    std::cin >> array[i];
  }

  auto pos = max_int(array, size);
  std::cout << "max element = " << array[pos] << " at position: " << pos
            << "\n";

  return 0;
}