#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>

class Employee {
private:
  std::string name;
  long number;

public:
  Employee();

  Employee(std::string &n, long num);

  void get_data();

  void put_data();
};

#include "employee.cpp"

#endif