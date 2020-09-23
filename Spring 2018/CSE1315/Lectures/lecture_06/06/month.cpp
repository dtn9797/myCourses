#include "month.h"

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
    default: return "Unknown"; break; // Or thrown a runtime exception
  }
}

ostream& operator<<(ostream& os, const Month& month) {
    os << month_to_string(month);
    return os;
}

Month& operator++(Month& m) {
  switch(m) {
    case Month::jan: m = Month::feb; break;
    case Month::feb: m = Month::mar; break;
    case Month::mar: m = Month::apr; break;
    case Month::apr: m = Month::may; break;
    case Month::may: m = Month::jun; break;
    case Month::jun: m = Month::jul; break;
    case Month::jul: m = Month::aug; break;
    case Month::aug: m = Month::sep; break;
    case Month::sep: m = Month::oct; break;
    case Month::oct: m = Month::nov; break;
    case Month::nov: m = Month::dec; break;
    case Month::dec: m = Month::jan; break;
    default: m = Month::jan; break;
  }
  return m;
}

Month operator++(Month& m, int) {
  Month result{m};
  ++m;
  return result;
}
