#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
	int iMatrix[4][4];
	//int iVector[4][1];
	int iVector[4];
	int iResult[4];
	//for(int iRowIdx=0;iRowIdx<
	
	/*
		Prompt user to enter values into the matrix
	*/
	for(int iRowIdx=0;iRowIdx<4;iRowIdx++)
	{
		for(int iColIdx=0;iColIdx<4;iColIdx++)
		{
			cout << "Enter values you want to enter for the matrix: " << endl;
			cin >> iMatrix[iRowIdx][iColIdx];
		}
	}

	/*
		Print matrix values 
	*/
	for(int i=0;i<4;i++)
	{
		
		for(int j=0;j<4;j++)
		{
			cout << iMatrix[i][j] << " ";
		}
		cout << endl;
	}
	
	/*
		Prompt user to enter values for vector
	*/
	for(int k=0;k<4;k++)
	{
		cout << "Enter the desired values for the column vector: " << endl;
		cin >> iVector[k];
	}

	/*
		Print values of vector for debugging purposes
	*/
	for(int j=0;j<4;j++)
	{
		cout << iVector[j] << endl;
	}

	int iTemp=0;
	for(int r=0;r<4;r++)
	{
		iTemp=0;
		for(int c=0;c<4;c++)
		{
		
			iTemp+=((iMatrix[r][c])*(iVector[c]));
		}
		iResult[r]=iTemp;
		//cout << "Value of iTemp is: " << iTemp << endl;
		//cout << "Value of iResult" << "[" << r <<"]"<<" is " <<iResult[r] << endl;
	}

	for(int z=0;z<4;z++)
	{
		cout << iResult[z] << endl;
	}




	/*
		Next, prompt user to enter values for the vector
	*/
	/*for(int k=0;k<4;k++)
	{
		for(int l=0;l<1;l++)
		{
			cin >> 
		}
	}*/


	return 0;
}
