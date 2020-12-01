#include "list.h"

template <class T> void List<T>::push_back(T value) {
  try {
    auto entry = new Entry{value};

    if (tail == nullptr) {
      tail = entry;
      head = entry;
    } else {
      entry->prev = tail;
      tail->next = entry;
      tail = entry;
    }
  }

  catch (Bad_alloc()) {
    std::cout << "bad_alloc\n";
  }
}

template <class T> List<T>::List() : head(nullptr), tail(nullptr) {}

template <class T> List<T>::List(std::initializer_list<T> &list) {
  for (auto &element : list) {
    push_back(element);
  }
}

template <class T> List<T>::List(const T &other) {
  head = other->head;
  tail = other->tail;
}

template <class T> void List<T>::push_front(T value) {
  try {
    auto entry = new Entry{value};

    if (tail == nullptr) {
      tail = entry;
      head = entry;
    } else {
      entry->next = head;
      head->prev = nullptr;
      head = entry;
    }
  } catch (Bad_alloc()) {
    std::cout << "bad_alloc\n";
  }
}

template <class T> T List<T>::pop_back() {
  try {
    if (tail == nullptr) {
      throw Is_empty();
    }

    auto tmp = tail->value;

    if (tail == head) {
      delete tail;
      head = nullptr;
      tail = nullptr;
    } else {
      auto new_tail = tail->prev;

      new_tail->next = nullptr;

      delete tail;

      tail = new_tail;
    }
    return tmp;
  } catch (Out_of_range()) {
    std::cout << "out_of_range\n";
  }
}

template <class T> T List<T>::pop_front() {
  try {
    if (head == nullptr) {
      throw Is_empty();
    }

    auto tmp = head->value;

    if (head == tail) {
      delete head;
      head = nullptr;
      tail = nullptr;
    } else {
      auto new_head = head->next;

      new_head->prev = nullptr;

      delete head;

      head = new_head;
    }
    return tmp;
  } catch (Out_of_range()) {
    std::cout << "out_of_range\n";
  }
}

template <class T> size_t List<T>::size() {
  int size = 0;

  if (head == nullptr) {
    return 0;
  } else {
    auto entry = head;

    while (entry != nullptr) {
      size++;
      entry = entry->next;
    }
  }

  return size;
}

template <class T> T &List<T>::operator[](const size_t &index) {
  if (size() == 0 || index > size()) {
    throw Out_of_range();
  }

  auto entry = head;

  for (int i = 0; i != index && i < index; i++) {
    entry = entry->next;
  }

  return entry->value;
}

template <class T>
void List<T>::for_each(std::function<void(Entry *)> callback) {
  auto entry = head;

  while (entry != nullptr) {
    callback(entry);
    entry = entry->next;
  }
}

template <class T> List<T>::~List() {
  auto entry = head;

  for_each([](auto entry) { delete entry; });
}

template <class T> void List<T>::display() {
  for_each([](auto entry) { std::cout << entry->value << " "; });
  std::cout << "\n";
}

template <class T> void List<T>::swap(T &t1, T &t2) {
  T tmp = t1;
  t1 = t2;
  t2 = tmp;
}

template <class T1> void heapify(List<T1> &list, int size, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < size && list[left] > list[largest])
    largest = left;

  if (right < size && list[right] > list[largest])
    largest = right;

  if (largest != i) {
    list.swap(list[i], list[largest]);

    heapify(list, size, largest);
  }
}

template <class T1> void heap_sort(List<T1> &list, int size) {
  for (int i = size / 2 - 1; i >= 0; i--)
    heapify(list, size, i);

  for (int i = size - 1; i > 0; i--) {
    list.swap(list[0], list[i]);

    heapify(list, i, 0);
  }
}
