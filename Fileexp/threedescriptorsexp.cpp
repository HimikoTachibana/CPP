#include <iostream>
#include <string>
using namespace std;

int main()
{

	int year=0;
	int age=0;

	string name = " ";
	cout << "What year was your favourite?\n";
	cin >> year;

	cout << "How interesting, your favourite year is " << year << "!\n";
	cout << "At what age did you learn to ride a bike? ";

	cin >> age;

	cout << "How interesting you learned to ride at " << age << "!\n";

	cout << "What is your name?: ";
	cin >> name;
	cout << "Hello "<<name<<"!\n";

	return 0;
}
