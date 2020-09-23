#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

int main () {
  cout << "Please enter name of output file: ";
  string oname;
  cin >> oname;

  ofstream ofs {oname};
  if (!ofs) throw runtime_error("can’t open output file " + oname);

  ofs << "Writing this to a file.\n";
  return 0;
}

