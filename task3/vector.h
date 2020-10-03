#ifndef _VECTOR_H_
#define _VECTOR_H_

class Vector {
private:
  int num;
  int *array;

public:
  Vector();

  Vector(int n);

  Vector(const Vector &vector);

  ~Vector();

  void fill_vector();

  void show_vector();

  void method();

  void sort_in_descending_order();

  int find_min_value();

  int find_max_value();

  float find_average_value();
};

#endif