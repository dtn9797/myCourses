#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "(1) cin>> or (2) cin.get? ";
    cin >> ch;
    cin.ignore();
    if (ch == '1') for ( ; cin>>ch     && ch != 'x'; ) cout << ch;
    else           for ( ; cin.get(ch) && ch != 'x'; ) cout << ch;
    cout << endl;
    return 0;
}
