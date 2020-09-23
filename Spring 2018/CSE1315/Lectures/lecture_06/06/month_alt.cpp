#include "month.h"
#include <map>

std::string month_to_string(Month m) {
  std::map<Month, std::string> m_to_str =
  {
     {Month::jan, "January"},
     {Month::feb, "February"},
     {Month::mar, "March"},
     {Month::apr, "April"},
     {Month::may, "May"},
     {Month::jun, "June"},
     {Month::jul, "July"},
     {Month::aug, "August"},
     {Month::sep, "September"},
     {Month::oct, "October"},
     {Month::nov, "November"},
     {Month::dec, "December"},
  };
  return m_to_str[m];
}

ostream& operator<<(ostream& os, const Month& month) {
    os << month_to_string(month);
    return os;
}

Month& operator++(Month& m) {
  std::map<Month, Month> next_month =
  { 
    {Month::jan, Month::feb},
    {Month::feb, Month::mar},
    {Month::mar, Month::apr},
    {Month::apr, Month::may},
    {Month::may, Month::jun},
    {Month::jun, Month::jul},
    {Month::jul, Month::aug},
    {Month::aug, Month::sep},
    {Month::sep, Month::oct},
    {Month::oct, Month::nov},
    {Month::nov, Month::dec},
    {Month::dec, Month::jan},
  };
  m = next_month[m];
  return m;
}

Month operator++(Month& m, int) {
  Month result{m};
  ++m;
  return result;
}

