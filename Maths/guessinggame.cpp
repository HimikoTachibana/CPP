#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <typeinfo>
using namespace std;

int main(int argc, char *argv[])
{
	int target=55;
	int guess=-1;
	cout << "Guess a number between 0 and 100: " << endl;
	cin >> guess;
	string sGuess="";
	cin >> sGuess;
	cout << "sGuess: " << &sGuess.at(0) << endl;
	//cout << "sGuess: " << strtol(sGuess) << endl;
	//cout  << atoi((sGuess.at(0))) << endl;
	//cout << "Type of guess is: " << typeid(guess).name() << endl;
	cout <<"Value of guess is: " <<guess << "\n";
	//guess='q';
	//cout <<"Value of guess: "<<guess <<"type of guess"<<typeid(guess).name() << "\n";
	//string sGuess = "";

	//cin >> sGuess;
	//cout << "Value of stop button is: " << sGuess << endl;
	//if(sGuess=="q")
	//{
		//cout << "Inside the if: " << endl;
		//exit(0);
	//}
	//bool bStopped=false;

	//while(bStopped!=true)
	//{

	//}
	//string sGuess="";

	while((guess != target))
	{
		//cin >> sGuess;
		//if(sGuess == "q")
		//{
			//cout << "The value of guess is: " << sGuess << endl;
			//break;
		//}
		//if(guess=='q' && guess<target)
		//{
			//exit(10);
		//}
		cout << "Value of guess: " << guess << endl;
 
		if(guess == 0)
		{
			guess=113;
			exit(0);
			break;
		}
		if(0<=guess && guess <= 100)
		{
			if(guess>target)
			{
				cout << "Guess too high" << endl;

				cout << "Guess again" << endl;
				cin >> guess; // have user guess again
			}
			/*else if(sGuess=="q")
			{
				exit(0);
				break;
			}*/
			//else if(guess == 'q')
			//{
				//exit(0);
			//}
			else if(guess<target)
			{
				//exit(0);
				//if(guess > 100)
				//{
					//exit(-1);
					//break;
				//}
				//else
				//{
					cout << "Guess too low" << endl;
					cout << "Guess again" << endl;
					cin >> guess;
				//}
				//exit(0);
				//cin >> guess; // have user guess again
			}

		//else if(guess=='q' && guess<target)
		//{
			//exit(0);
		//}
			else
			{
				cout << "Guess correct" << endl;
				//break;

			}

			
		}
		//else if((char)guess=='q')
		//{
			//exit(0);
			//break;

		//}
		//else if(guess==113)
		//{
			//break;
			//exit(0);
		//}
		//else
		//{
			//break;
			//exit(0);
		//}
		//if(guess==113)
		//{
			//exit(0);
			//break;
		//}
		//cin>>sGuess;
	}
	/*while(guess != target || sGuess == "q")
	{

		
		if(guess>target)
		{
			cout << "Your guess is too high: " << endl;
			cin >> guess;
		}
		else if(guess<target)
		{
			cout << "Your guess is too low" << endl;
			cin >> guess;
		}
		else
		{
			cout << "Your guess is correct" << endl;

		}
		cin >> sGuess;
	}*/


	return 0;
}
