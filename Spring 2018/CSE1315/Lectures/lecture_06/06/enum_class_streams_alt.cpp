#include "date_method.h"
#include <iostream>
using namespace std;

int main() {
    Date unix_epoch;  // or unix_epoch{}

    // Here we use the operator<< METHOD (from date_method.h) for the Date class.

    // Because C++ always puts the object FIRST in the method call, we are forced 
    // to put the data before the cout! (Switch the order and try to build it...)

    // Obviously, this isn't something you would ever do in a real program, but
    // now hopefully you understand why.  :-)
    unix_epoch << cout << endl;

    Date my_birthday{1950, Month::dec, 30};  // OK
    my_birthday << cout << endl;
}
