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

    std::string sex;
  };

  std::vector<data> array;

public:
  void load_from_file(const std::string &file_name);

  void load_to_file(const std::string &file_name);

  void add_person();

  void display_person(data &person);

  void display_array();

  void sort_by_surname();

  void sort_by_age();

  void display_by_month(int month);

  void the_oldest_man();

  void display_by_surname(char first_letter);
};

#endif