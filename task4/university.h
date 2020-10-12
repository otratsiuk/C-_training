#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <string>

class University {
private:
  std::string name;
  std::string city;

public:
  University();

  University(std::string uni_name, std::string uni_city);

  ~University();

  void fill(std::string uni_name, std::string uni_city);

  void display();
};

class Faculty : public University {
private:
  int teachers; // number of teachers
  int students; // number of students

public:
  Faculty();

  Faculty(std::string uni_name, std::string uni_city, int teachers_num,
          int students_num);

  ~Faculty();

  void fill(std::string uni_name, std::string uni_city, int teachers_num,
            int students_num);

  void display();

  int total_value_of_students(int num_of_faculties);
};

class Course : public University {
private:
  int number;   // course number
  int students; // number of students

public:
  Course();

  Course(std::string uni_name, std::string uni_city, int num, int students_num);

  ~Course();

  void fill(std::string uni_name, std::string uni_city, int num,
            int students_num);

  void display();

  int total_value_of_students(int num_of_courses);
};

class Group : public University {
private:
  std::string speciality;
  int students; // number of students

public:
  Group();

  Group(std::string uni_name, std::string uni_city, std::string spec,
        int students_num);

  ~Group();

  void fill(std::string uni_name, std::string uni_city, std::string spec,
            int students_num);

  void display();

  int total_value_of_students(int num_of_groups);
};

#endif