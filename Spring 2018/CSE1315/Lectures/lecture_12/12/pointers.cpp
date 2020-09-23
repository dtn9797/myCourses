#include <iostream>
using namespace std;

class Foo {
  public:
    int bar = 42;
};

int main()
{
    Foo foo1;
    cout << "Direct access  -  foo1.bar:   " << foo1.bar << endl;
    Foo *foo2;
    foo2 = &foo1;
    cout << "Pointer access - (*foo2).bar: " << (*foo2).bar << endl;
    cout << "Arrow access  -  foo2->bar:   " << foo2->bar << endl;
    Foo *foo3 = new Foo{ };
    cout << "Pointer access - (*foo3).bar: " << (*foo3).bar << endl;
    cout << "Arrow access  -  foo3->bar:   " << foo3->bar << endl;
    delete[ ] foo3;
}
