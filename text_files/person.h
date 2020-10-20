#ifndef _PERSON_H_
#define _PERSON_H_
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
  void load_from_file(const std::string &file_name)
}

#endif