#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main () {
	char *buf;
	buf =(char*)malloc(10*sizeof(char));
	cuserid(buf);
	cout<< "Hello, " << buf <<"!"<< endl;
	return 0;
}
