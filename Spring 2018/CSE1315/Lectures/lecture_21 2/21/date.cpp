#include <iostream>

enum class Month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
std::string month_to_string(Month m) {
  switch(m) {
    case Month::jan: return "January"; break;
    case Month::feb: return "February"; break;
    case Month::mar: return "March"; break;
    case Month::apr: return "April"; break;
    case Month::may: return "May"; break;
    case Month::jun: return "June"; break;
    case Month::jul: return "July"; break;
    case Month::aug: return "August"; break;
    case Month::sep: return "September"; break;
    case Month::oct: return "October"; break;
    case Month::nov: return "November"; break;
    case Month::dec: return "December"; break;
    default: return "Unknown"; break;
  }
}

class Date {
  public:
    Date(int y, Month m, int d) : year{y}, month{m}, day{d} { }
    Date() : Date(1970, Month::jan, 1) { }
    void set_date(int y, Month m, int d) {year=y; month=m; day=d;}
    void print_date() {std::cout << month_to_string(month) << " " <<
                        day << ", " << year << std::endl;}
  private:
    int year;
    Month month;
    int day;
};

int main() {
    Date unix_epoch;  // or unix_epoch{} - Default constructor
    unix_epoch.print_date();
    Date my_birthday{1950, Month::dec, 30};  // Non-default constructor
    my_birthday.print_date();
}

