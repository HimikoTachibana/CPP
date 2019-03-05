#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{

	float fResult=10.0;
	float *fResTemp;
	fResTemp=&fResult;

	cout << "fResTemp is: " << fResTemp << endl;
	cout << "&fResTemp is: " << &fResTemp << endl;
	cout << "*fResTemp is: " << *fResTemp << endl;
	//cout << "&&fResTemp is: " << &&fResTemp << endl;
	return 0;

}
