#include "university.h"
#include <iomanip>
#include <iostream>
#include <string>

// class University
University::University() : name("unknown"), city("unknown") {}

University::University(std::string uni_name, std::string uni_city)
    : name(uni_name), city(uni_city) {}

University::~University() {}

void University::fill(std::string uni_name, std::string uni_city) {
  name = uni_name;
  city = uni_city;
}

void University::display() {
  std::cout << "\n"
            << std::setw(30) << std::left
            << "university name: " << std::setw(40) << std::right << name
            << "\n";
  std::cout << std::setw(30) << std::left
            << "university city: " << std::setw(40) << std::right << city
            << "\n";
}

// class Faculty
Faculty::Faculty() : University() {
  University();

  teachers = 0;
  students = 0;
}

Faculty::Faculty(std::string uni_name, std::string uni_city, int teachers_num,
                 int students_num)
    : University(uni_name, uni_city) {
  University(uni_name, uni_city);

  teachers = teachers_num;
  students = students_num;
}

Faculty::~Faculty() {}

void Faculty::fill(std::string uni_name, std::string uni_city, int teachers_num,
                   int students_num) {
  University::fill(uni_name, uni_city);

  teachers = teachers_num;
  students = students_num;
}

void Faculty::display() {
  University::display();

  std::cout << std::setw(30) << std::left
            << "number of faculty teachers: " << std::setw(40) << std::right
            << teachers << "\n"
            << std::setw(30) << std::left
            << "number of faculty students: " << std::setw(40) << std::right
            << students << "\n\n";
}

int Faculty::total_value_of_students(int num_of_faculties) {
  return (num_of_faculties * students);
}

// class Course
Course::Course() : University() {
  University();

  number = 0;
  students = 0;
}

Course::Course(std::string uni_name, std::string uni_city, int num,
               int students_num)
    : University(uni_name, uni_city) {
  University(uni_name, uni_city);

  number = num;
  students = students_num;
}

Course::~Course() {}

void Course::fill(std::string uni_name, std::string uni_city, int num,
                  int students_num) {
  University::fill(uni_name, uni_city);

  number = num;
  students = students_num;
}

void Course::display() {
  University::display();

  std::cout << std::setw(30) << std::left << "Course number: " << std::setw(40)
            << std::right << number << "\n"
            << std::setw(30) << std::left
            << "number of students: " << std::setw(40) << std::right << students
            << "\n\n";
}

int Course::total_value_of_students(int num_of_courses) {
  return (num_of_courses * students);
}

// class Group
Group::Group() : University() {
  University();

  speciality = "unknown";
  students = 0;
}

Group::Group(std::string uni_name, std::string uni_city, std::string spec,
             int students_num)
    : University(uni_name, uni_city) {
  University(uni_name, uni_city);

  speciality = spec;
  students = students_num;
}

Group::~Group() {}

void Group::fill(std::string uni_name, std::string uni_city, std::string spec,
                 int students_num) {
  University::fill(uni_name, uni_city);

  speciality = spec;
  students = students_num;
}

void Group::display() {
  University::display();

  std::cout << std::setw(30) << std::left
            << "group speciality: " << std::setw(40) << std::right << speciality
            << "\n"
            << std::setw(30) << std::left
            << "number of students: " << std::setw(40) << std::right << students
            << "\n\n";
}

int Group::total_value_of_students(int num_of_groups) {
  return (num_of_groups * students);
}