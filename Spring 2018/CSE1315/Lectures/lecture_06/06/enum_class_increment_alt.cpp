#include "date_method.h"
#include <iostream>
using namespace std;

int main() {
    // Post-increment in a 3-term for
    Month m{Month::oct};
    for (int i = 0; i<6; ++i) cout << m++ << endl;
    cout << endl;

    // Wait - use the month as the "counter"! w/Pre-increment
    for (Month m=Month::oct; m != Month::apr ; ++m) cout << m << endl;

}
