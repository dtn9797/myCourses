enum class Month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

class Date {
  public:
    Date(int y, Month m, int d) : year{y}, month{m}, day{d} { }
  private:
    int year;
    Month month;
    int day;
};

int main() {
    // Date my_birthday(1950, 30, Month::dec);  // error: 2nd argument not a Month
    Date my_birthday(1950, Month::dec, 30);  // OK
}
