#include "person.h"
#include <iostream>

void menu() {
  int key;

  std::cout
      << "\n1 - load data from file\n2 - load data to file\n3 - add person\n4 "
         "- "
         "sort alphabetically by surname\n5 - sort by age\n6 - display people "
         "by month\n7 - display "
         "by first surname letter\n8 - display data\n0 - exit\noption: ";
}

int main() {
  std::string file_name = "file.txt";

  Person database;

  bool next = true;

  while (next) {
    int key;

    menu();

    std::cin >> key;

    switch (key) {
    case 1: {
      database.load_from_file(file_name);

      std::cout << "\nloaded from file\n";
      break;
    }
    case 2: {
      database.load_to_file(file_name);

      std::cout << "\nloaded to file\n";
      break;
    }
    case 3: {
      database.add_person();

      std::cout << "\nperson is added\n";
      break;
    }
    case 4: {
      database.sort_by_surname();

      std::cout << "\ndatabase is sorted by surname\n";
      break;
    }
    case 5: {
      database.sort_by_age();

      std::cout << "\ndatabase is sorted by age\n";
      break;
    }
    case 6: {
      int month;
      std::cout << "enter month: ";
      std::cin >> month;

      database.display_by_month(month);
      break;
    }
    case 7: {
      char letter;
      std::cout << "enter the first surname letter: ";
      std::cin >> letter;

      database.display_by_surname(letter);
      break;
    }
    case 8: {
      database.display_array();
      break;
    }
    case 0: {
      next = false;
      break;
    }
    default: {
      std::cout << "\nno such option\n";
      break;
    }
    }
  }
  return 0;
}