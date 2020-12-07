#include "employee.h"
#include <iomanip>
#include <iostream>

Employee::Employee() : name("unknown"), number(0) {}

Employee::Employee(std::string &n, long num) : name(n), number(num) {}

void Employee::get_data() {
  std::cout << "Enter name: ";
  std::cin >> name;
  std::cout << "Enter number: ";
  std::cin >> number;
}

void Employee::put_data() {
  std::cout << std::left << std::setw(20) << name << std::setw(20) << number
            << "\n";
}