#include "derived.h"
#include <iostream>
#include "new_derived.h"
int main () {
  Derived d(1,2);

  std::cout << d.get_sum();
  return 0;
}
