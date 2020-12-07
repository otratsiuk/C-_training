#ifndef _SHAPE_H
#define _SHAPE_H

#include <SFML/Graphics.hpp>

const double pi = 3.14159265359;

class Shape {
public:
  virtual double square() = 0;
  virtual double perimeter() = 0;
  virtual void draw(int x_pos, int y_pos) = 0;
};

class Circle : public Shape {
private:
  double radius;

public:
  Circle(double r);

  double square() override;

  double perimeter() override;

  void draw(int x_pos, int y_pos) override;
};

class Rectangle : public Shape {
private:
  double width;
  double length;

public:
  Rectangle(double w, double l);

  double square() override;

  double perimeter() override;

  void draw(int x_pos, int y_pos) override;
};

class Square : public Shape {
private:
  double side;

public:
  Square(double s);

  double square() override;

  double perimeter() override;

  void draw(int x_pos, int y_pos) override;
};

#include "shape.cpp"
#endif