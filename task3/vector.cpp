#include "vector.h"
#include <cmath>
#include <iostream>

Vector::Vector() : num(10) { array = new int[num]; }

Vector::Vector(int n) : num(n) { array = new int[n]; }

Vector::Vector(const Vector &vector) {
  num = vector.num;
  array = vector.array;
}

Vector::~Vector() { delete[] array; }

void Vector::fill_vector() {
  std::cout << "Enter elements:\t";

  for (int i = 0; i < num; i++) {
    std::cin >> array[i];
  }
}

void Vector::show_vector() {
  for (int i = 0; i < num; i++) {
    std::cout << array[i] << " ";
  }
}

void Vector::method() {
  int middle = ceil(num / 2);
  int elements_before_middle = middle;

  if (num % 2 != 0) {
    middle++;
  }

  for (int i = 0; i < elements_before_middle; i++) {
    if (i % 2 == 0 && (middle + i) % 2 != 0) {
      int temp = array[i];
      array[i] = array[middle + i];
      array[middle + i] = temp;
    }
  }
}

void Vector::sort_in_descending_order() {
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < num - i - 1; j++) {
      if (array[j] < array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int Vector::find_min_value() {
  int min = array[0];

  for (int i = 1; i < num; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

int Vector::find_max_value() {
  int max = array[0];

  for (int i = 1; i < num; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

float Vector::find_average_value() {
  int sum = 0;

  for (int i = 0; i < num; i++) {
    sum += array[i];
  }

  return static_cast<float>(sum) / num;
}
