#include "date.h"

Date::Date(int y, Month m, int d) : year{y}, month{m}, day{d} { }
Date::Date() : Date(1970, Month::jan, 1) { }

ostream& operator<<(ostream& os, const Date& date) {
    os << date.month << " " << date.day << ", " << date.year;
    return os;
}

