#include <iostream>
using namespace std;

enum class Month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
string month_to_string(Month m) {
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
    void set_date(int y, Month m, int d) {year=y; month=m; day=d;}
    void print_date() {cout << month_to_string(month) << " " << 
                        day << ", " << year << endl;}
  private:
    int year;
    Month month;
    int day;
};

int main() {
    Date my_birthday;
    my_birthday.print_date();
    my_birthday.set_date(1950, Month::dec, 30);  // OK
    my_birthday.print_date();
}
