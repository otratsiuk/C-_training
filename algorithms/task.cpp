#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <list>
#include <random>

template <typename Iterator> Iterator partition(Iterator begin, Iterator end) {
  auto pivot = --end;
  auto i = begin;

  for (auto j = begin; j != pivot; ++j) {
    if (*j <= *pivot) {
      std::iter_swap(i, j);
      i++;
    }
  }
  std::iter_swap(i, pivot);
  return i;
}

template <typename Iterator> void my_qsort(Iterator begin, Iterator end) {
  if (begin != end) {
    Iterator pivot = partition(begin, end);
    my_qsort(begin, pivot);
    my_qsort(++pivot, end);
  }
}

template <typename Iterator, typename T>
Iterator my_binary_search(Iterator begin, Iterator end, T value) {
  auto left = begin;
  auto right = --end;

  while (true) {
    if (begin == end) {
      return end;
    }
    auto counter = std::distance(left, right) / 2;
    Iterator medium = left;
    for (int i = 0; i < counter; i++) {
      medium++;
    }
    if (*medium < value)
      left = ++medium;
    if (*medium > value)
      right = --medium;
    if (*medium == value)
      return medium;
  }
}

template <typename T> void display(std::list<T> &list) {
  for (auto &e : list) {
    std::cout << e << " ";
  }
  std::cout << "\n";
}

int main() {
  // sort
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(-1000, 1000);

  std::list<int> my_list;

  for (int i = 0; i < 40; i++) {
    my_list.push_back(distribution(generator));
  }

  std::list<int> list = my_list;

  display(my_list);

  auto my_start = std::chrono::system_clock::now();
  my_qsort(my_list.begin(), my_list.end());
  auto my_end = std::chrono::system_clock::now();

  std::chrono::duration<double> my_time = my_end - my_start;

  std::cout << "sorted by implemented qsort:\n";
  display(my_list);

  std::cout << "\n"
            << std::left << std::setw(65)
            << "time for implemented qsort algorithm: " << std::setw(20)
            << my_time.count() << "\n";

  auto start = std::chrono::system_clock::now();
  list.sort();
  auto end = std::chrono::system_clock::now();

  std::chrono::duration<double> time = end - start;

  std::cout << std::left << std::setw(65)
            << "time for list standart sort algorithm: " << std::setw(20)
            << time.count() << "\n\n";

  // search
  auto my_search_start = std::chrono::system_clock::now();
  std::list<int>::iterator my_it =
      my_binary_search(my_list.begin(), my_list.end(), 178);
  auto my_search_end = std::chrono::system_clock::now();

  std::chrono::duration<double> my_search_time =
      my_search_end - my_search_start;

  std::cout << *my_it << std::setw(62)
            << " found with binary_search implementation in: " << std::setw(20)
            << my_search_time.count() << "\n";

  auto search_start = std::chrono::system_clock::now();
  std::list<int>::iterator it = std::find(list.begin(), list.end(), 178);
  auto search_end = std::chrono::system_clock::now();

  std::chrono::duration<double> search_time = search_end - search_start;

  std::cout << *it << std::setw(62)
            << " found with std::find in: " << std::setw(20)
            << search_time.count() << "\n\n";

  return 0;
}
