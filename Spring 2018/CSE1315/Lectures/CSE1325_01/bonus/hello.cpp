#include <iostream>
using namespace std;

int main (){
	cout << "Enter your full name:";
	string full_name;
	getline(cin,full_name);
	cout <<"Hello," << full_name << endl;
	return 0;
}
