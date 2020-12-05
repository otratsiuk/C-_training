#include "queue.h"

template <class T> void Queue<T>::push_back(T value) {
  if (tail < max_size - 1) {
    tail++;
    array[tail] = value;
  } else if (tail == max_size - 1 && head > 0) {
    for (int i = head, j = 0; i <= tail; i++, j++) {
      array[j] = array[i];
    }
    tail = max_size - 1 - head;
    head = 0;

    push_back(value);
  } else if (tail >= max_size - 1 && head <= 0) {
    throw Out_of_range();
  }
}

template <class T> Queue<T>::Queue() : head(-1), tail(-1) {}

template <class T> Queue<T>::Queue(std::initializer_list<T> &queue) {

  if (queue.size() > max_size) {
    throw Out_of_range();
  }

  if (queue.size() > 0) {
    head = 0;

    for (auto &element : queue) {
      push_back(element);
    }
  }
}

template <class T> T Queue<T>::pop_front() {
  if (head == tail + 1) {
    head = -1;
    tail = -1;
  }

  if (head == -1) {
    throw Is_empty();
  }

  auto tmp = array[head];

  head++;

  return tmp;
}

template <class T> void Queue<T>::display() {
  for (int i = head; i <= tail; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << "\n";
}

template <class T> void Queue<T>::fill(size_t size) {
  if (size > max_size) {
    throw Out_of_range();
  }

  for (int i = 0; i < size; i++) {
    std::cin >> array[i];
  }
  head = 0;
  tail = size;
}

template <class T> T &Queue<T>::operator[](const size_t &index) {
  if (head == -1 || index > max_size - 1) {
    throw Out_of_range();
  }

  return array[index];
}