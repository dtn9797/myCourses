#include <iostream>

template <class T>
class vector {
   int sz;       // the size
   T* elem;      // a pointer to the elements
public:
   vector(int s) : sz(s), elem{new T[s]} { }
   ~vector() {delete[ ] elem; }
   T get(int n) const { return elem[n]; }  // access: read
   void set(int n, T v) { elem[n]=v; }     // access: write
};

int main() {
  vector<double> d{10};
  d.set(3, 3.14);
  if (d.get(3) != 3.14) std::cerr << "For double, got " << d.get(3) 
                                  << ", not 3.14!" << std::endl;

  vector<std::string> s{10};
  s.set(9, "Hello");
  if (s.get(9) != "Hello") std::cerr << "For string, got " << s.get(9) 
                                     << ", not Hello!" << std::endl;
}


