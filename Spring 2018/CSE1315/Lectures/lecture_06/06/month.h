#ifndef __MONTH_H
#define __MONTH_H

#include <iostream>
using namespace std;

enum class Month {jan, feb, mar, 
                  apr, may, jun, 
                  jul, aug, sep, 
                  oct, nov, dec};

std::string month_to_string(Month m);
Month& operator++(Month& m);
Month operator++(Month& m, int);
ostream& operator<<(ostream& os, const Month& month);

#endif
