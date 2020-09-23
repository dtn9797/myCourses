#include "month.h"
#include <iostream>
using namespace std;

class Date {
  public:
    Date(int y, Month m, int d) : year{y}, month{m}, day{d} { }
    void print_date() {cout << month_to_string(month) << " " << 
                        day << ", " << year << endl;}
  private:
    int year;
    Month month;
    int day;
};

int main() {
    Date my_birthday{1950, Month::dec, 30};  // OK
    my_birthday.print_date();
}
