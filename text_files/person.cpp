#include "person.h"
#include <algorithm>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

std::ofstream &operator<<(std::ofstream &file, Person::data &person) {
  file << " " << person.surname << " " << person.name << " "
       << person.patronymic << " " << person.bd_day << " " << person.bd_month
       << " " << person.bd_year;

  return file;
}

Person::data &operator>>(std::ifstream &file, Person::data &person) {
  file >> person.surname >> person.name >> person.patronymic >> person.bd_day >>
      person.bd_month >> person.bd_year;

  return person;
}

void Person::load_from_file(const std::string &file_name) {
  std::ifstream file(file_name);

  array.clear();

  if (!file.is_open()) {
    std::cout << "file error\n";
  } else {
    while (!file.eof()) {
      data person;

      file >> person;

      array.push_back(person);
    }
    file.close();
  }
}

void Person::load_to_file(const std::string &file_name) {
  std::ofstream file(file_name, std::ios::trunc);

  if (!file.is_open()) {
    std::cout << "file error\n";

  } else {
    for (auto &person : array) {
      file << person;
    }

    file.close();
  }
}

void Person::add_person() {
  data person;

  std::cout << "\nenter data:\n"
            << "surname: ";
  std::cin >> person.surname;
  std::cout << "name: ";
  std::cin >> person.name;
  std::cout << "patronymic: ";
  std::cin >> person.patronymic;

  try {
    std::cout << "bd_day: ";
    std::cin >> person.bd_day;

    if (person.bd_day < 1 || person.bd_day > 31) {
      throw -1;
    }
    std::cout << "bd_month: ";
    std::cin >> person.bd_month;

    if (person.bd_month < 1 || person.bd_month > 12) {
      throw -1;
    }
    std::cout << "bd_year: ";
    std::cin >> person.bd_year;

    if (person.bd_year < 1920 || person.bd_year > 2020) {
      throw -1;
    }

  } catch (int) {
    std::cerr << "\nwrong data input\n";

    add_person();
  }

  array.push_back(person);
}

void Person::display_person(data &person) {
  std::cout << std::setw(30) << std::left << person.surname << std::setw(30)
            << person.name << std::setw(30) << person.patronymic << std::setw(4)
            << person.bd_day << std::setw(4) << person.bd_month << std::setw(6)
            << person.bd_year << "\n";
}

void Person::display_array() {
  std::cout << "\n";

  for (auto &person : array) {
    display_person(person);
  }

  std::cout << "\n";
}

void Person::sort_by_surname() {
  std::sort(array.begin(), array.end(),
            [](const auto &a, const auto &b) { return a.surname < b.surname; });
}

void Person::sort_by_age() {
  std::sort(array.begin(), array.end(), [](const auto &a, const auto &b) {
    return (a.bd_year < b.bd_year) ||
           (a.bd_year == b.bd_year && a.bd_month < b.bd_month) ||
           (a.bd_year == b.bd_year && a.bd_month == b.bd_month &&
            a.bd_day < b.bd_day);
  });
}

void Person::display_by_month(int month) {
  std::cout << "\n";

  for (auto &person : array) {
    if (month == person.bd_month) {
      display_person(person);
    }
  }
}

void Person::display_by_surname(char first_letter) {
  std::cout << "\n";

  for (auto &person : array) {
    if (person.surname[0] == first_letter) {
      std::cout << person.surname << "\n";
    }
  }
}
