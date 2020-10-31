#ifndef _CLASSES_H_
#define _CLASSES_H_
#include <string>

class Educational_organization {
public:
  virtual void show() = 0;
};

class Secondary_education : public Educational_organization {
protected:
  int number;
  int maths_average;
  int language_average;
  int physics_average;

public:
  Secondary_education();
  Secondary_education(int num, int maths, int language, int physics);

  virtual float average_points() = 0;
};

class Higher_education : public Educational_organization {
protected:
  std::string name;
  int num_of_students;

public:
  Higher_education();
  Higher_education(const std::string &n, int num);

  virtual int general_num_of_students(int num) = 0;
};

class School : public Secondary_education {
public:
  School();
  School(int num, int maths, int language, int physics);

  void show();
  float average_points();
};

class Gymnasium : public Secondary_education {
private:
  int num_of_grades;

public:
  Gymnasium();
  Gymnasium(int num, int grades, int maths, int language, int physics);

  void show();
  float average_points();
};

class University : public Higher_education {
private:
  std::string specialization;

public:
  University();
  University(const std::string &name, const std::string &spec, int num);

  int get_students();
  void show();
  int general_num_of_students(int num);
};

class Institute : public Higher_education {
public:
  Institute();
  Institute(const std::string &name, int num);

  int get_students();
  void show();
  int general_num_of_students(int num);
};

#endif