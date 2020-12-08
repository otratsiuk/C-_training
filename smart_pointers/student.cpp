#include "student.h"

Student::Student(const std::string &_surname, int _age, int _course,
                 const std::string _group)
    : surname(_surname), age(_age), course(_course), group(_group) {
  std::cout << "constructor with parameters\n";
}

Student ::Student(Student &&other)
    : surname(other.surname), age(other.age), course(other.course),
      group(other.group) {
  other.surname = "0";
  other.age = 0;
  other.course = 0;
  other.group = "0";

  std::cout << "move constructor (Student &&other)\n";
}

Student::Student(const Student &other) {
  surname = other.surname;
  age = other.age;
  course = other.course;
  group = other.group;

  std::cout << "copy constructor (const Student &other)\n";
}

void Student ::display() {
  std::cout << std::left << std::setw(20) << surname << std::setw(5) << age
            << std::setw(5) << course << std::setw(5) << group << "\n";
}

Student::~Student() { std::cout << "destructor\n"; }
