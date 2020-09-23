#include <iostream>
using namespace std;

class A {
  public:
    virtual void m() {cout << "m of A" << endl;}
};

class B : public virtual A {
  public:
    virtual void m() override;
};

void B::m() {cout << "m of B" << endl;}

class C : public virtual A { };
    
class D : public B, public C { };

int main() {
  D d;
  d.A::m();
  d.B::m();
  d.C::m();
}

