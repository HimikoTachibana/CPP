#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	char gameboard[4][4]={
		{'x','-','-','-'},
		{'-','-','-','-'},
		{'-','-','x','-'},
		{'-','-','-','x'}
	};

	char cUser='x';
	int iCountX=0;
	// counter to represent the amount of xs on the main diagonal
	int iCountO=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{

			if(cUser=='x')
			{
				if(i==j && gameboard[i][j]==cUser)
				{
					cout << "There are 4" << cUser << " 's on main diagonal" << endl;

					cout<< gameboard[i][j] << endl;
					iCountX++;
				}

				if((gameboard[i][j]==cUser)
				&&(gameboard[i][j]==gameboard[i+1][j])
				&&(gameboard[i+1][j]==gameboard[i+2][j])
				&&(gameboard[i+2][j]==gameboard[i+3][j]))
				{
					cout << "There are four x's in a column" << endl;
					
				}

				if((gameboard[i][j]==cUser)
				  &&(gameboard[i][j]==gameboard[i][j+1])
				  &&(gameboard[i][j+1]==

			}
			if(cUser=='o')
			{
				if(i==j && gameboard[i][j]==cUser)
				{
					iCountO++;
				}
				if((gameboard[i][j]==cUser) && 
				(gameboard[i][j]==gameboard[i+1][j])
				&& (gameboard[i+1][j]==gameboard[i+2][j])
				&& (gameboard[i+2][j] == gameboard[i+3][j]))
				{
					cout << "Four o's in the same column" << endl;
				}
				if((gameboard[i][j]==cUser)
				&&(gameboard[i][j]==gameboard[i][j+1])
				&&(gameboard[i][j+1]==gameboard[i][j+2])
				&&(gameboard[i][j+2]==gameboard[i][j+3])
				{
					cout << "Four o's in the same row" << endl;
				}
			}
		}
	}


	cout << iCountO << endl;
	cout << iCountX<< endl;
}
