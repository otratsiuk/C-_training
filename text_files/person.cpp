#include "person.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

void Person::load_from_file(const std::string &file_name) {
  std::ifstream file(file_name);

  if (!file.is_open()) {
    std::cout << "can't open file\n";

  } else {
    while (!file.eof()) {
      data temp;

      file >> temp.surname >> temp.name >> temp.patronymic >> temp.bd_day >>
          temp.bd_month >> temp.bd_year >> temp.sex;

      array.push_back(temp);
    }

    file.close();
  }
}

void Person::load_to_file(const std::string &file_name) {
  std::ofstream file(file_name, std::ios::trunc);

  if (!file.is_open()) {
    std::cout << "can't open file\n";

  } else {
    for (auto &person : array) {
      file << " " << person.surname << " " << person.name << " "
           << person.patronymic << " " << person.bd_day << " "
           << person.bd_month << " " << person.bd_year << " " << person.sex;
    }

    file.close();
  }
}

void Person::add_person() {
  data temp;

  std::cout << "enter data:\n"
            << "surname: ";
  std::cin >> temp.surname;
  std::cout << "name: ";
  std::cin >> temp.name;
  std::cout << "patronymic: ";
  std::cin >> temp.patronymic;
  std::cout << "bd_day: ";
  std::cin >> temp.bd_day;
  std::cout << "bd_month: ";
  std::cin >> temp.bd_month;
  std::cout << "bd_year: ";
  std::cin >> temp.bd_year;
  std::cout << "sex: ";
  std::cin >> temp.sex;

  array.push_back(temp);
}

void Person::display_person(data &person) {
  std::cout << std::setw(30) << std::left << person.surname << std::setw(30)
            << person.name << std::setw(30) << person.patronymic << std::setw(4)
            << person.bd_day << std::setw(4) << person.bd_month << std::setw(6)
            << person.bd_year << std::setw(10) << person.sex << "\n";
}

void Person::display_array() {
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
  for (auto &person : array) {
    if (month == person.bd_month) {
      display_person(person);
    }
  }
}

void Person::the_oldest_man() {
  sort_by_age();
  for (auto &person : array) {
    if (person.sex == "male") {
      std::cout << person.surname << "\n";
      break;
    }
  }
}

void Person::display_by_surname(char first_letter) {
  for (auto &person : array) {
    if (person.surname[0] == first_letter) {
      std::cout << person.surname << "\n";
    }
  }
}
