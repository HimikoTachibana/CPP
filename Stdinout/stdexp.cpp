#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	int iTurn=8;
	int i=0;
	int iAge=-1;
	int iAge2=-1;
	vector<int> v;
	//cin >> iAge;
	//cin >> iAge2;
	while(i<iTurn)
	{
		//cin >> iAge2;
		cout<< "Value of i is: " << i << endl;
		cin >> iAge;
		cout << "Value for player one's age is: " << iAge << endl;
		cin >> iAge2;
		cout << "Value for player two's age is: " << iAge2 << endl;
		i++;
	}

	//cout << iAge;
}
