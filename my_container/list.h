#ifndef _LIST_H
#define _LIST_H

#include <cassert>
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

  Entry *head = NULL;
  Entry *tail = NULL;

public:
  void push_back(T value) {

    auto entry = new Entry{value};

    if (tail == NULL) {
      tail = entry;
      head = entry;
    } else {
      entry->prev = tail;
      tail->next = entry;
      tail = entry;
    }
  };

  List(std::initializer_list<T> &list) {
    for (auto &element : list) {
      push_back(element);
    }
  };

  void push_front(T value) {
    auto entry = new Entry{value};

    if (tail == NULL) {
      tail = entry;
      head = entry;
    } else {
      entry->next = head;
      head->prev = NULL;
      head = entry;
    }
  };

  T pop_back() {
    assert(tail);

    auto tmp = tail->value;

    if (tail == head) {
      delete tail;
      head = NULL;
      tail = NULL;
    } else {
      auto new_tail = tail->prev;

      new_tail->next = NULL;

      delete tail;

      tail = new_tail;
    }

    return tmp;
  };

  T pop_front() {
    assert(head);

    auto tmp = head->value;

    if (head == tail) {
      delete head;
      head = NULL;
      tail = NULL;
    } else {
      auto new_head = head->next;

      new_head->prev = NULL;

      delete head;

      head = new_head;
    }
    return tmp;
  }

  void for_each(std::function<void(Entry *)> callback) {
    auto entry = head;

    while (entry->next != NULL) {
      callback(entry);
      entry = entry->next;
    }
  };

  void display() {
    for_each([](auto entry) { std::cout << entry->value << " "; });
    std::cout << "\n";
  }
};

void sort();

void find();

#endif