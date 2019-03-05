#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
/*
	This is a class that represents a gameboard:
		private members: 
			the game board itself
			expressed in a 0 index based n by n matrix
			where each element is a C character
		public members: 
			C'tor- initializes all the array elements
			to a particular default character

			Method that sets a particular element
			at the ith row, jth column to the specified character
			
			Method that gets a particular element
			at the ith row, jth column

			Method that returns a size 3 array i.e 
			of the form [a,b,c]
			containing a flag that represents the following.
				a- denotes whether or not we have
				found four x's or four o's in the main
				diagonal or the other main diagnal
				b- denotes whether or not we have found
				we have found four o's or x's in the same column

				c- denotes whether or not we have four o's or x's
				in the same row.
*/
class Gameboard{

	
	private:
		char gamespace[4][4];
		int fourInaRow(char cPlayerCharacter);
		int fourInaCol(char cPlayerCharacter);
		int fourInaReverseDiagnol(char cPlayerCharacter);
		int fourInMainDiagonol(char cPlayerCharacter);
	public:
		Gameboard();
		void setBoardSquare(int iRow, int iCol,char cSet);
		char getBoardSquare(int iRow, int iCol);
		int *fourConsecNeighbours(char cPlayerCharacter);

		//int fourInaRow(char cPlayerCharacter);
		//int fourInaCol(char cPlayerCharacter);
		//int fourInReverseDiagnol(char cPlayerCharacter);
		//int fourInMainDiagnol(char cPlayerCharacter);
		void printInfo();

};

#endif
