#include <iostream>
#include <typeinfo>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
	const bool char_is_signed = (char)-1<0;
	int guess=-1;
	/*cout << "Enter a number" << endl;
	cin >> guess;
	cout << guess << endl;
	cout << "Enter a character" << endl;
	cin >> guess;
	cout << "Guess value is: " << guess << endl;*/
	//guess='q';


	/*Note to self, cin can be only used for one variable of one type*/

	char sInput[256];
	cout << "Enter a character" << endl;
	cin.getline(sInput,256);
	cout <<"sInput value" <<sInput << endl;
	int iConv=0;
	iConv=atoi(&sInput[0]);
	cout << "Value of iConv= " << iConv << endl;
	if(char_is_signed == true)
	{
		cout << "Char is true" << endl;
	}
	
	cout << char_is_signed << endl;
	cout << typeid('q').name() << endl;

	if(guess>0)
	{
		cout << "Guess is greater than 0" << endl;
	}

	if(guess==113)
	{
		cout << "Inside if" << endl;
	}

	
	return 0;
}
