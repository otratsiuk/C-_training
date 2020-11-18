#include <iomanip>
#include <iostream>
#include <string>

// Task1
struct Student {
  std::string surname;
  std::string name;
  std::string faculty;
  int group;
  std::string email;
};

struct Another_order {
  int group;
  std::string email;
  std::string surname;
  std::string name;
  std::string faculty;
};

std::ostream &operator<<(std::ostream &output, Student student) {
  output << std::left << std::setw(30) << student.surname << std::setw(30)
         << student.name << std::setw(30) << student.faculty << std::setw(15)
         << student.group << std::setw(30) << student.email;
  ;

  return output;
}

int main() {
  // Task2
  Student array[5];

  // Task3
  int n = 8;
  // std::cout << "enter number of students in dynamic array: ";
  // std::cin >> n;

  Student *dynamic_array = new Student[n];

  // Task4
  array[0] = {"surname1", "name1", "faculty", 1, "email"};
  array[1] = {"surname2", "name2", "faculty", 16, "email"};
  array[2] = {"surname3", "name3", "faculty", 43, "email"};
  array[3] = {"surname4", "name4", "faculty", 2, "email"};
  array[4] = {"surname5", "name5", "faculty", 3, "email"};

  dynamic_array[0] = {"dsurname", "dname", "dfaculty", 53, "demail"};

  std::cout << "\nTask4\n";

  std::cout << *array << "\n"; // Access to first student in array using *
  std::cout << *dynamic_array << "\n"; //

  // Task5
  std::cout << "\nTask5\n";

  std::cout << "size of array: " << sizeof(array) << " bytes\n";

  Student *ptr = array;
  std::cout << "size of poiter to array: " << sizeof(ptr) << " bytes\n";

  // Task6
  std::cout << "\nTask6\n";

  Student *adress = array;
  Student *parray = array;

  for (int i = 0; i < 4; i++) {
    auto prev = adress;

    std::cout << *(parray++) << std::setw(30) << adress++ << "\n";

    std::cout << "difference: " << adress - prev << "\n";
  }

  // Task7
  std::cout << "\nTask7\n";

  Student structure1;
  std::cout << &structure1.surname << "\n" << &structure1.name << "\n";

  // Task8
  std::cout << "\nTask8\n";

  Another_order structure2;
  std::cout << "size of structure 1: " << sizeof(structure1) << "\n";
  std::cout << "size of structure 2: " << sizeof(structure2) << "\n";

  std::cout << "\nadresses for structure1:\n"
            << &structure1.surname << "\n"
            << &structure1.name << "\n"
            << &structure1.group << "\n"
            << &structure1.faculty << "\n"
            << &structure1.email << "\n";

  std::cout << "\nadresses for structure2:\n"
            << &structure2.group << "\n"
            << &structure2.email << "\n"
            << &structure2.surname << "\n"
            << &structure2.name << "\n"
            << &structure2.faculty << "\n";

  return 0;
}