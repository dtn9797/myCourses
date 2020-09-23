#include "date_method.h"

Date::Date(int y, Month m, int d) : year{y}, month{m}, day{d} { }
Date::Date() : Date(1970, Month::jan, 1) { }

ostream& Date::operator<<(ostream& os) {
    os << this->month << " " << this->day << ", " << this->year;
    return os;
}

