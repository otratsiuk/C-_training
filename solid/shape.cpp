#include "shape.h"

Circle::Circle(double r) : radius(r) {}

double Circle::square() { return (pi * radius * radius); }

double Circle::perimeter() { return (2 * pi * radius); }

void Circle ::draw(int x_pos, int y_pos) {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Circle");

  sf::CircleShape shape(radius);
  shape.setFillColor(sf::Color::Blue);
  shape.setPosition(x_pos, y_pos);

  while (window.isOpen()) {
    window.clear();

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.draw(shape);
    window.display();
  }
}

Rectangle::Rectangle(double w, double l) : width(w), length(l) {}

double Rectangle::square() { return (width * length); }

double Rectangle::perimeter() { return (2 * (width + length)); }

void Rectangle::draw(int x_pos, int y_pos) {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Rectangle");

  sf::RectangleShape shape(sf::Vector2f(width, length));
  shape.setFillColor(sf::Color::Green);
  shape.setPosition(x_pos, y_pos);

  while (window.isOpen()) {
    window.clear();

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.draw(shape);
    window.display();
  }
}

Square::Square(double s) : side(s) {}

double Square::square() { return side * side; }

double Square::perimeter() { return 4 * side; }

void Square ::draw(int x_pos, int y_pos) {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Square");

  sf::CircleShape shape(side, 4);
  shape.setFillColor(sf::Color::Red);
  shape.setPosition(x_pos, y_pos);

  while (window.isOpen()) {
    window.clear();

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.draw(shape);
    window.display();
  }
}
