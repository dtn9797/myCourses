
 #include "age.h"
 #include <iostream>

 int main() {
   bool passed = true;

   Age m1(Age::restricted);
   if (m1.to_string() != "restricted") {
     passed = false;
     cerr << "restricted failed: got " << m1.to_string() << endl;
   }

   if (!passed) {
     cerr << "fail" << endl;
     return -1;
   }

   return 0;
 }
