#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
int main(int argc, char *argv[])
{
	char gameboard[4][4]={
		{'x','-','-','x'},
		{'x','-','x','-'},
		{'x','-','y','x'},
		{'x','-','-','-'}
	};

	int iXRow=-1;
	/*
		Aside: Funf is the number four in German
		so we keep two boolean flags, one for all the x's in a row
		the other in a column
	*/
	bool bfunfRow=false; 
	bool bfunfCol=false;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{

			if( (gameboard[i][j] == 'x')&&(gameboard[i][j] == gameboard[i][j+1]) 
			&& (gameboard[i][j+1] == gameboard[i][j+2]) && (gameboard[i][j+2] == gameboard[i][j+3]) )
			{
				//printf("There are four x's in a row \n");
				bfunfRow=true;
				iXRow=i;
				//printf("That row is located at: %d\n",i);
			}
			if( (gameboard[i][j] == 'x') && (gameboard[i][j] == gameboard[i+1][j])
			&& ( gameboard[i+1][j] == gameboard[i+2][j]) && (gameboard[i+2][j] == gameboard[i+3][j]) )
			{
				bfunfCol=true;
				iXRow=-1;
			}

			
			/*for(int k=0;k<2;k++)
			{
				if( (gameboard[i][j] == 'x') && (gameboard[i][j+k]==gameboard[i][j+k+1]))
				{
					//printf("The value of i is %d\n",i);
					//printf("The value of j is %d\n",j);
					//printf("The value of k is %d\n",k);
					bfunfRow=true;
					iXRow=i;
				}
				else if( (gameboard[i][j] == 'x') && (gameboard[i+k][j]==gameboard[i+k+1][j]) )
				{
					//printf("Value of i: %d\n",i);
					//printf("Value of j: %d\n",j);
					//printf("Value of bfunfCol is: %d\n",bfunfCol);
					bfunfCol=true;
					iXRow=-1;
				}
				printf("\n\n Value of i is: %d\n ",i);
				printf("\n\n Value of j is: %d\n",j);
				printf("\n\n Value of k is: %d\n",k);
				printf("\n\n Value of iXRow: %d\n",iXRow);
				printf("\n\n gameboard[i][j] %c\n",gameboard[i][j]);
				printf("\n\n gameboard[i][j+k] %c\n",gameboard[i][j+k]);
				printf("\n\n gameboaard[i][j+k+1] %c\n",gameboard[i][j+k+1]);
				printf("\n\n gameboard[i+k][j] %c\n", gameboard[i+k][j]);
				printf("\n\n gameboard[i+k+1][j] %c\n", gameboard[i+k+1][j]);
			
			}*/
			//printf("%c",gameboard[i][j]);
		}
		//printf("\n");
	}

	printf("Value of bfunfRow %d\n",bfunfRow);
	printf("Value of bfunfCol %d\n",bfunfCol);
	if(bfunfRow == true && bfunfCol == false)
	{
			printf("Four in a row found \n");
	}
	if(iXRow != -1)
	{
		printf("That row is located on row %d\n",iXRow);
	}
	return 0;
}
