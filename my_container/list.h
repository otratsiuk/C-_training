#ifndef _LIST_H
#define _LIST_H

#include <functional>
#include <initializer_list>
#include <iostream>

template <class T> class List {
private:
  struct Entry {
    T value;
    Entry *prev;
    Entry *next;
  };

  Entry *head = nullptr;
  Entry *tail = nullptr;

  void for_each(std::function<void(Entry *)> callback);

public:
  class Iterator {
  private:
    Entry *entry;

  public:
    Iterator(Entry *_entry);

    bool operator==(Iterator const &other) const;

    bool operator!=(Iterator const &other) const;

    T operator*() const;

    Iterator &operator++(int);
  };

  Iterator begin() const;

  Iterator end() const;

  class Is_empty {};

  class Out_of_range {};

  class Bad_alloc {};

  void push_back(T value);

  List();

  List(std::initializer_list<T> &list);

  List(const T &other);

  void push_front(T value);

  T pop_back();

  T pop_front();

  size_t size();

  T &operator[](const size_t &index);

  ~List();

  void display();

  void swap(T &t1, T &t2);

  template <class T1> friend void heapify(List<T1> &list, int size, int i);

  template <class T1> friend void heap_sort(List<T1> &list, int size);
};

#include "iterator.cpp"
#include "list.cpp"

#endif