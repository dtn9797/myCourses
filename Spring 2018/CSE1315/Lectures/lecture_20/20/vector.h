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

