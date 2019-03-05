#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string line;
	fstream fMyfile("test.txt", fstream::in | fstream::out);
	if(fMyfile.is_open())
	{
		fMyfile << "\n I am adding a line. \n";
		fMyfile << "I am adding another line. \n";

		fMyfile << "WTAF! \n";
		fMyfile.close();
	}
	else
	{
		cout << "In return one if";
		cout << "Unable to open file" << endl;
		return 1;
	}

	fMyfile.open("test.txt",fstream::in| fstream::out| fstream::app);

	if(fMyfile.is_open())
	{
		while(getline(fMyfile,line))
		{
			cout << line << '\n';
		}
		fMyfile.close();
	}
	else
	{
		cout << "In return 3 if" << "\n";
		cout << "Unable to open file" << "\n";
		return 3;
	}
	
}
