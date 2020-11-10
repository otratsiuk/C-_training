#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <cassert>
#include <initializer_list>
#include <iostream>

template <class T> class Array {
private:
  T *arr;
  int size;

public:
  Array() : arr(nullptr), size(0){};

  Array(const std::initializer_list<T> &list) : size(list.size()) {
    arr = new T[size];

    int i = 0;
    for (auto &element : list) {
      arr[i] = element;
      i++;
    }
  };

  ~Array() { delete[] arr; };

  void show() {
    for (int i = 0; i < size; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << "\n";
  };

  float method() {
    assert(size != 0 || arr != nullptr && "empty array");

    float mean = 0;

    for (int i = 0; i < size; i++) {
      mean += static_cast<float>(arr[i]);
    }

    return mean / size;
  };
};

#endif