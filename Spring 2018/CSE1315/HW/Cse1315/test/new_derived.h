#include "base.h"

class NDerived : public Base {
  public:
    NDerived (int e, int f): Base(e,f) {};
    int get_sum() {return a+b;};
};
