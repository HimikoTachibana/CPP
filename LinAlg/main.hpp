#include <iostream>
#include <iomanip>
using namespace std;

class Gameboard
{
	char gameSpace[4][4];

	public:
		Gameboard();
		void setGameSpace(int row, int column, char value);
		char getGameSpace(int row,int column);
		int fourInRow();
		void printInfo();
};

Gameboard::Gameboard()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			gameSpace[i][j]='-';
		}
	}
}

void Gameboard::setGameSpace(int row, int column, char value)
{
	gameSpace[row][column]=value;
}

char Gameboard::getGameSpace(int row, int column)
{
	return gameSpace[row][column];
}

int Gameboard::fourInRow()
{
	int iFound=0;
	int bFunfRow=0;
	int bFunfCol=0;
	int iXRow=-1;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{


			if( (gameSpace[i][j] == 'x')&&(gameSpace[i][j] == gameSpace[i][j+1]) 
			&& (gameSpace[i][j+1] == gameSpace[i][j+2]) && (gameSpace[i][j+2] == gameSpace[i][j+3]) )
			{
				//printf("There are four x's in a row \n");
				bFunfRow=1;
				iXRow=i;
				//printf("That row is located at: %d\n",i);
			}
			if( (gameSpace[i][j] == 'x') && (gameSpace[i][j] == gameSpace[i+1][j])
			&& ( gameSpace[i+1][j] == gameSpace[i+2][j]) && (gameSpace[i+2][j] == gameSpace[i+3][j]) )
			{
				bFunfCol=1;
				iXRow=-1;
			}
		}
	}

	if(bFunfRow == 1 && bFunfCol == 0)
	{
		iFound=1;

	}
	return iFound;
}

void Gameboard::printInfo()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout << gameSpace[i][j] << " ";
		}
		cout << endl;
	}
}
