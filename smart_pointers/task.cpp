#include "student.h"
#include <algorithm>
#include <list>
#include <memory>
#include <vector>

void display(std::vector<std::unique_ptr<Student>> &vec) {
  std::cout << "__________________________________________\n\n";
  for (auto &e : vec) {
    (*e).display();
  }
  std::cout << "__________________________________________\n\n";
}

int main() {
  std::list<Student> list = {
      Student("Hoppus", 20, 3, "AI"),   Student("Barker", 20, 3, "MB"),
      Student("Delonge", 18, 1, "MS"),  Student("Ellefson", 22, 5, "AI"),
      Student("Harrison", 22, 5, "AI"), Student("Mustaine", 22, 5, "AI")};

  std::vector<std::unique_ptr<Student>> students;
  for (auto &e : list) {
    students.push_back(std::make_unique<Student>(std::move(e)));
  }

  display(students);

  std::string field = "surname";

  auto functor = [field](std::unique_ptr<Student> &a,
                         std::unique_ptr<Student> &b) -> bool {
    if (field == "surname") {
      return a->surname < b->surname;
    }
    if (field == "age") {
      return a->age < b->age;
    }
    if (field == "course") {
      return a->course < b->course;
    }
    if (field == "group") {
      return a->group.length() < b->group.length();
    }
  };

  std::sort(students.begin(), students.end(), functor);

  display(students);

  students.clear();

  return 0;
}