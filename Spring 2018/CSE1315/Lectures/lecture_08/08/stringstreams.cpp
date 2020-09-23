#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

double str_to_double(string s) {
    istringstream iss{s}; // make an input stream from s
    double d;
    iss >> d;             // stream a double from s
    if (!iss) throw runtime_error("double format error");
    return d;
}

string double_to_string(double d) {
    ostringstream oss;	// make a stream so that we can read from s
    oss << d;
    if (!oss) throw runtime_error("string format error");
    return oss.str();
}

int main() {
    double d1 = str_to_double("12.4");
    double d2 = str_to_double("1.34e-3");
    // double d3 = str_to_double("twelve point three"); // will throw exception

    string s1 = double_to_string(12.4);
    string s2 = double_to_string(1.34e-3);
    string s3 = double_to_string(NAN);

    cout << d1 << ' ' << d2 << endl;
    cout << s1 << ' ' << s2 << ' ' << s3 << endl;

    return 0;
}
