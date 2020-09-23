#ifndef __DATE_METHOD_H
#define __DATE_METHOD_H

#include "month.h"
#include <iostream>
#include <ostream>
using namespace std;

class Date {
  public:
    Date(int y, Month m, int d);
    Date();
    ostream& operator<<(ostream& os);
  private:
    int year;
    Month month;
    int day;
};

#endif
