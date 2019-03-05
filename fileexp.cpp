#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string line;
	ofstream myfileI ("input.txt", ios::app);
	if(myfileI.is_open())
	{
		myfileI << "\nI am adding a line. \n";
		myfileI << "I am adding another line. \n";
		myfileI.close();

	}
	else
	{
		cout << "Unable to open file for writing";
	}
	ifstream myfile0("input.txt");
	if(myfile0.is_open())
	{
		while(getline(myfile0, line))
		{
			cout << line << '\n';
		}
		myfile0.close();
	}
	else
	{
		cout << "Unable to open file for reading:";
		return 0;
	}
}
