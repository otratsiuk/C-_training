#include "list.h"

template <class T> typename List<T>::Iterator List<T>::begin() const {
  return Iterator(head);
}

template <class T> typename List<T>::Iterator List<T>::end() const {
  return Iterator(nullptr);
}

template <class T> List<T>::Iterator::Iterator(Entry *_entry) : entry(_entry) {}

template <class T>
bool List<T>::Iterator::operator==(const Iterator &other) const {
  return this == &other;
}

template <class T>
bool List<T>::Iterator::operator!=(const Iterator &other) const {
  return this != &other;
}

template <class T> T List<T>::Iterator::operator*() const {
  if (entry) {
    return entry->value;
  } else {
    throw Out_of_range();
    return T();
  }
}

template <class T>
typename List<T>::Iterator &List<T>::Iterator::operator++(int) {
  if (entry) {
    entry = entry->next;
    return *this;
  } else {
    throw Out_of_range();
  }
}