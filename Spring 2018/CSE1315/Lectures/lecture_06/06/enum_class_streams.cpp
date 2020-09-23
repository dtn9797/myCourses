#include "month.h"
#include "date.h"
#include <iostream>
using namespace std;

int main() {
    Date unix_epoch;  // or unix_epoch{}
    cout << unix_epoch << endl;
    Date my_birthday{1950, Month::dec, 30};  // OK
    cout << my_birthday << endl;
}
