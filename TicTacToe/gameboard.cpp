#include "gameboard.h"


// To do: 
Gameboard::Gameboard()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			gamespace[i][j]='-';
		}
	}
}

void Gameboard::setBoardSquare(int iRow, int iCol, char cSet)
{
	gamespace[iRow][iCol]=cSet;
}

char Gameboard::getBoardSquare(int iRow, int iCol)
{
	return gamespace[iRow][iCol];
}


// A function that checks for four of a specific element
// in a consecutive row, column, the main diagonal, or the reverse diagonal
//	 Notation:
//		pvalue[0]=0 // there is four in a row for the 'x' player
/*				// 1 denotes four in a row for the 'o' player
		pvalue[1]=0 //0 means there is four in a column for the 'x' player
			   // 1 means there is four in a column for the 'o' player

		pvalue[2]=0 // 0 means there is four in the main diagonal
				for the 'x' player
				1 means there is four in the main diagonal
				for the 'o' player

		pvalue[3]=0 // 0 means there is four in the reverse diagonal
				for the 'x' player
			   // 1 means there is four in the reverse diagonal 
				for the 'o' player
*/
int * Gameboard::fourConsecNeighbours(char cPlayerCharacter)
{
	//int *iBitArray=(int *)malloc(3*sizeof(int));
	int *pvalue=NULL;
	pvalue = new int[4];
	int *boolbox=NULL;
	boolbox= new int[4];
	/*initialize booleans elements to 0*/
	for(int i=0;i<3;i++)
	{
		pvalue[i]=0;
	}

	boolbox[0]=fourInaRow(cPlayerCharacter);
	boolbox[1]=fourInaCol(cPlayerCharacter);
	boolbox[2]=fourInMainDiagonol(cPlayerCharacter);
	boolbox[3]=fourInaReverseDiagnol(cPlayerCharacter);
	for(int i=0;i<4;i++)
	{
		/*if(cPlayerCharacter=='x' && boolbox[0]==1)
		{
			pvalue[0]=0;
		}
		else if(cPlayerCharacter=='o' && boolbox[0]==0)
		{
			pvalue[0]=1;
		}
		else if(cPlayerCharacter=='x' && boolbox[1]==*/

		if(cPlayerCharacter=='x' && boolbox[i]==1)
		{
			pvalue[i]=0;
		}
		else if(cPlayerCharacter=='o' && boolbox[i]==1)
		{
			pvalue[i]=1;
		}


	}


	
	/*int iFunfCol=0;
	int iFunfRow=0;

	for(int j=0;j<4;j++)
	{
		for(int k=0;k<4;k++)
		{

			if((gameboard[i+0][j] == cPlayerCharacter)&&
				(gameboard[i+0][j]==gameboard[i+1][j]) &&
				(gameboard[i+1][j]==gameboard[i+2][j]) &&
				(gameboard[i+2][j]==gameboard[i+3][j])
			)
			{
				iFunfCol=1;
			}
			if((gameboard[i][j]==cPlayerCharacter) &&
			(gameboard[i][j+0]==gameboard[i][j+1])
			(gameboard[i][j+1]==gameboard[i][j+2])
			(gameboard[i][j+2]==gameboard[i][j+3])
			{
				iFunfRow=1;
			}
			
		}
	}*/
	return pvalue;
}

int Gameboard::fourInaRow(char cPlayerCharacter)
{
	int iFunfRow=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if((gamespace[i][j]==cPlayerCharacter)&&(gamespace[i][j]==gamespace[i][j%4]))
			{
				iFunfRow=1;
			}
		}
	}
	return iFunfRow;
}

int Gameboard::fourInaCol(char cPlayerCharacter)
{
	int iFunfCol=0;

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(
			(gamespace[i][j]==cPlayerCharacter)
					&&
			(gamespace[i][j]==gamespace[i%4][j])
			
			)
			{
				iFunfCol=1;
			}
		}
	}
	return iFunfCol;
}

int Gameboard::fourInMainDiagonol(char cPlayerCharacter)
{
	int iFunfMainDiag=0;
	int iCount=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(i==j)
			{
				if(gamespace[i][j]==cPlayerCharacter)
				{
					iFunfMainDiag=1;
				}
			}
			//iFunfMainDiag=1;
		}
	}
	return iFunfMainDiag;
}

int Gameboard::fourInaReverseDiagnol(char cPlayerCharacter)
{
	int iFunfReverse=0;
	int iCount=0;
	for(int i=0;i<4;i++)
	{
		for(int j=4;j>0;j--)
		{
			if(i==4-j)
			{
				if(gamespace[i][j]==cPlayerCharacter)
				{
					iCount++;
				}
				//iFunfReverse=0;
			}
		}
	}

	if(iCount==4)
	{
		iFunfReverse=1;
	}
	return iFunfReverse;
}
