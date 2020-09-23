#ifndef __DATE_H
#define __DATE_H

#include "month.h"
#include <iostream>
#include <ostream>
using namespace std;

class Date {
  public:
    Date(int y, Month m, int d);
    Date();
    friend ostream& operator<<(ostream& os, const Date& date);
  private:
    int year;
    Month month;
    int day;
};

ostream& operator<<(ostream& os, const Date& date);

#endif
