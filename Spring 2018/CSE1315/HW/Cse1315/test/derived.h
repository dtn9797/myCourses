#include <iostream>
#include <string>
using namespace std;
class Derived {
  public:
    int a;
    int b;
    Derived (int e, int f): a{e},b{f} {};
    string get_sum();
};
