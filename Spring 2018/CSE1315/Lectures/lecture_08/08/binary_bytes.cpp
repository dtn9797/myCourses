#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filename; 

    cout << "Please enter input file name\n";
    getline(cin, filename);
    ifstream ifs {filename,ios_base::binary};  // note: binary
    if (!ifs) {cerr << "Can't open input file: aborted" << endl; return -1;}

    cout << "Please enter output file name\n";
    getline(cin, filename);
    ofstream ofs {filename, ios_base::binary};	// note: binary
    if (!ofs) {cerr << "Can't open output file: aborted" << endl; return -2;}

    char byte;
    int counter = 0;
    while(ifs) {
        ifs.get(byte);
        if (ifs) {
            ofs.put(byte);
            if (!ofs) {cerr << "File write error: aborted" << endl; return -4;}
        }
        if (!(++counter % 256)) cout << ".";
    }
    cout << endl;
    if (!ifs.eof()) {
        cerr << "File read error: aborted" << endl;
        return -3;
    }
    return 0;
}
