#ifndef _QUEUE_H
#define _QUEUE_H

#include <initializer_list>
#include <iostream>

template <class T> class Queue {
private:
  const static int max_size = 30;
  T array[max_size];

  int head = -1;
  int tail = -1;

public:
  class Is_empty {};

  class Out_of_range {};

  void push_back(T value);

  T pop_front();

  Queue();

  Queue(std::initializer_list<T> &queue);

  void fill(size_t size);

  void display();

  T &operator[](const size_t &index);
};

#include "queue.cpp"

#endif