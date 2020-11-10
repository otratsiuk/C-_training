#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include <vector>

class Person {
public:
  struct data {
    std::string surname;
    std::string name;
    std::string patronymic;

    int bd_day;
    int bd_month;
    int bd_year;
  };

  std::vector<data> array;

public:
  friend std::ofstream &operator<<(std::ofstream &file, Person::data &person);

  friend Person::data &operator>>(std::ifstream &file, Person::data &person);

  void load_from_file(const std::string &file_name);

  void load_to_file(const std::string &file_name);

  void add_person();

  void display_person(data &person);

  void display_array();

  void sort_by_surname();

  void sort_by_age();

  void display_by_month(int month);

  void display_by_surname(char first_letter);
};

#endif