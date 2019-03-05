#include "main.hpp"

int main(int argc, char *argv[])
{

	Gameboard gamein;
	gamein.setGameSpace(0,0,'x');
	gamein.setGameSpace(0,1,'x');
	gamein.setGameSpace(0,2,'x');
	gamein.setGameSpace(0,3,'y');

	gamein.setGameSpace(1,0,'x');

	gamein.setGameSpace(2,0,'x');

	gamein.setGameSpace(3,0,'x');
	//gamein.setGameSpace(3,1,'x');
	gamein.setGameSpace(3,2,'x');
	gamein.setGameSpace(3,3,'x');

	if(gamein.fourInRow() == 1)
	{
		cout << "X got four in a row! \n\n";
	}
	else
	{
		cout << "X did not get four in a row :(\n\n";
	}
	gamein.printInfo();
	return 0;
}
