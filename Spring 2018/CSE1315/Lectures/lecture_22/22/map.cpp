#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>
using namespace std;

int main() {
    // With vectors (using int as the index type)
    vector<string> s;
    s.push_back("Maps rock");
    for (int i=0; i < s.size(); ++i) 
       cout << i << " = " << s[i] << endl;

    // With maps (using string as the index type)
    map<string, string> m;
    m.insert(make_pair("earth", "home"));
    for (map<string, string>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " = " << it->second << endl;
    }
}

