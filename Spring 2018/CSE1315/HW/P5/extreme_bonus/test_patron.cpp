#include "patron.h"

int main() {
  bool passed = true;

  string name = "Professor Rice";
  string number = "817-555-1212";

  Patron p(name, number);

  if (p.get_patron_name() != name) {
    passed = false;
    cerr << "Name was '" << p.get_patron_name() << 
          "' should be '" << name << "'" << endl;
  }

  if (p.get_patron_phone_number() != number) {
    passed = false;
    cerr << "Number was '" << p.get_patron_phone_number()  << 
          "' should be '" << number << "'" << endl;
  }

  if (!passed) {
    cerr << "fail" << endl;
    return -1;
  }

  return 0;
}
