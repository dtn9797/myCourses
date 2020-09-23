#include<iostream>
using namespace std;
 
class A {
  public: A()  { cout << "A's constructor called" << endl; }
};
 
class B {
  public: B()  { cout << "B's constructor called" << endl; }
};
 
class C: public A, public B {
  public: C()  { cout << "C's constructor called" << endl; }
};
 
int main() {
    C c;
}
