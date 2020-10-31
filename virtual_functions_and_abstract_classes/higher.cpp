#include "classes.h"
#include <string>

Higher_education::Higher_education() : name("unknown"), num_of_students(0){};

Higher_education::Higher_education(const std::string &n, int num)
    : name(n), num_of_students(num){};
