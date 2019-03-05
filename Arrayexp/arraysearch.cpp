#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;



/*
	Function that takes an array and returns an integer that denotes
	the index [0 based indexing] where a particular element is at
		-1 at failure, the index otherwise

*/
int LinearSearch(int *arr,int n,int iKey)
{
	int iLoc = -1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==iKey)
		{
			iLoc=i;
		}
	}
	return iLoc;
}

int main(int argc, char *argv[])
{
	int iAmount=10;
	int searchArray[iAmount]={324,4567,6789,542135,7,65,8965,12,342,485};
	int searchKey;
	//int iQuit=-1;
	//bool bFound = false;
	int location=-1;
	//scanf("%d",&iQuit);

	/*
		There is an array of integers, the length of the arrays to be searched varies.
		A user will enter an integer, and the program will search the array.
		If the value is in the array, the program will return the location of the element
		If the value is not in the array, the user will be notified that the search key is not found
			To exit the program the user enters -1
	*/
	/*while(iQuit != 1)
	{
		scanf("%d",&searchKey); // need only one int? for the quit signal?
		for(int i=0;i<iAmount;i++)
		{
			if(searchArray[i] == 
		}
		scanf("%d",&iQuit);
	}*/
	printf("This program will allow you, the user to search for a value in the array\n");
	printf("return its particular location and notify you if the value is not there\n");
	int iEnters=0; // Counter to keep track amount of times the user enters thier desired search key

	// Design decision, if searchvalue is not found, we prompt user to enter another search value
	// note to self in C++ the && operation performs short circut evaluation
	// so for example in bool1 && bool2
	// if bool1 is false it does not need to check for bool2

	//scanf("%d",&searchKey);
	//cout << "Value of your key is: " << searchKey << endl;

	//location=LinearSearch(searchArray,iAmount,searchKey);
	//cout << "Value of location is: " << location << endl;
	// Hypothesis: location variable is not being reset after the first iteration
	while(searchKey != -1)
	{
		
		if(iEnters==0)
		{
			printf("Enter your search key or press -1 to quit,\n");
		}
		if(iEnters>0)
		{
			printf("Enter another search key or press -1 to quit,\n");
		}
		//printf("Enter your search key or press -1 to quit,\n");
		scanf("%d",&searchKey); // Note to self: scanf will also exit if EOF signal is raised to main
		location=LinearSearch(searchArray,iAmount,searchKey);
		if(location != -1)
		{
			cout << "The search key " << searchKey << " is at index: " << location << endl;
			//cout << "Would you like to enter another value to search for another one?" << endl;
			//scanf("%d",&searchKey);
			//location=LinearSearch(searchArray,iAmount,searchKey);
		}
		else{

			if(searchKey != -1)
			{
				cout << "Your search key is not in the array,the search key was: " << searchKey << endl;
			}
			//cout << "Your search key is not in the array, the search key was: " << searchKey << endl;
			//cout << "Please enter another number: " << endl;
			//scanf("%d",&searchKey);
			//location=LinearSearch(searchArray,iAmount,searchKey);
		}
		iEnters++;
		//scanf("%d",&searchKey);	

	}
	cout << iEnters << endl;
	//int iIndex=0;
	//while((bFound != true && iIndex<iAmount)|| (location<0))
	/*while(iIndex<iAmount)
	{
		//scanf("%d", &searchKey);
		if(searchKey==-1)
		{
			break;
		}
		if(searchArray[iIndex] == searchKey)
		{
			location=iIndex;
		}
		if(location == -1)
		{
			cout << "Inside location==-1 if: " << endl;
			break;
			//exit(0);
		}
		iIndex++;

	}*/
	//printf("Your search key's location in terms of indices is: %d\n",location);
	//int iPos=location+1;
	//printf("Your search key's location in terms of its position is: %d\n",iPos);
	return 0;
}
