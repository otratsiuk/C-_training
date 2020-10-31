#include "classes.h"
#include <string>

Secondary_education::Secondary_education()
    : number(0), maths_average(0), language_average(0), physics_average(0){};

Secondary_education::Secondary_education(int num, int maths, int language,
                                         int physics)
    : number(num), maths_average(maths), language_average(language),
      physics_average(physics){};
