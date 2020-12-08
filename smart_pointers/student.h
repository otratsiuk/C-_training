#ifndef _STUDENT_H
#define _STUDENT_H

#include <iomanip>
#include <iostream>
#include <string>

class Student {
public:
  std::string surname;
  int age;
  int course;
  std::string group;

  Student(const std::string &_surname, int _age, int _course,
          const std::string _group);

  Student(Student &&other);

  Student(const Student &other);

  void display();

  ~Student();
};

#include "student.cpp"

#endif
