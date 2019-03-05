#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	int iAmount=4;
	int userInput[iAmount];

	//int iTemp=-1;
	for(int k=0;k<iAmount;k++)
	{
		userInput[k]=0;
	}
	for(int i=0;i<iAmount;i++)
	{
		//cin >> iTemp;
		//userInput[i]=iTemp;
		cin >> userInput[i];
	}

	/*Print array in forward order i.e [a,b,c,d]*/

	for(int r=0;r<iAmount;r++)
	{
		cout << userInput[r] << " ";
	}
	cout << endl;

	/*Print array in reverse order i.e [d,c,b,a]*/
	for(int j=iAmount;j>0;j--)
	{
		cout << userInput[j-1] << " ";
	}
	cout << endl;
	
	// Sort the array
	sort(userInput,userInput+iAmount);

	// Print the sorted array 
	for(int s=0;s<iAmount;s++)
	{
		cout << userInput[s] << " ";
	}
	cout << endl;


}
