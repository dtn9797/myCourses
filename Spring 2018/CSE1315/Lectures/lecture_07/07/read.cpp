#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

// …
int main()
{
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    // The following line only works in later C++ versions, e.g., 11
    ifstream ist {iname};	// ifstream is an“input stream from a file”
				// defining an ifstream with a name string
				// opens the file of that name for reading
    if (!ist) throw runtime_error("can’t open input file " + iname);
    string aline;
    while (getline(ist, aline)) cout << aline << endl;
}
