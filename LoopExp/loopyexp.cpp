#include <iostream>
using namespace std;

int main()
{
	int m=7;


	char gameboard[4][4]={
		{'-','-','-','x'},
		{'-','-','x','-'},
		{'-','x','-','-'},
		{'x','-','-','-'}
	};

	char gbz[4][4]={
		{'x','-','-','-'},
		{'-','x','-','-'},
		{'-','-','x','-'},
		{'-','-','-','x'}
	};

	char gRowCheck[4][4]={
		{'-','-','-','-'},
		{'x','x','x','x'},
		{'-','-','-','-'},
		{'-','-','-','-'}
	};

	char gColCheck[4][4]={
		{'-','-','x','-'},
		{'-','-','x','-'},
		{'-','-','x','-'},
		{'-','-','x','-'}
	};

	int indexArr[4]={0,1,2,3};

	for(int i=-8;i<=10;i++)
	{
		cout <<"i is: " << i << endl;
		cout << (i%m) << endl;
	}

	cout << "Backwards loop" << endl;
	int j=4;

	for(int i=0;i<4;i++)
	{
		for(int k=j;k>0;k--)
		{
			
			//cout << "Value of 4-k: " << 4-k << " ";
			//cout << endl;

			if(i==4-k)
			{
				if(gameboard[i][k-1] == 'o')
				{
					cout << gameboard[i][k-1] << " ";
				}
				//cout << gameboard[i][k-1] << " ";
				if(gameboard[i][k-1]=='x')
				{
					cout << "X" << endl;
				}
			}
			//cout << gameboard[i][k-1] << " ";
			//if(i==k-1)
			//{
				//cout << "Value of i" << i << endl;
				//cout << "Value of k -1 is: " << k << endl;
				//cout<<gameboard[i][k-1]<<endl;
			//}
		}
		cout << endl;
	}

	cout << "Checking main diagonal " << endl;

	for(int i=0;i<4;i++)
	{
		for(int j=-0;j<4;j++)
		{
			if(i==j)
			{
				cout << "Value is:  "<< gbz[i][j] << endl;
			}
		}
	}
	/*for(int k=j;k>0;k--)
	{
		cout << k-1 << endl;
		//cout << "Testing increments" << endl;
		//cout <<"k-1+1 " << k-1+1 << endl;
		//cout >> "k-1+2" << k-1+2 << endl;
		//cout >> "k-1+3" << k-1+3 << endl;
	}*/

	cout << "Checking for four in a row" << endl;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if((gRowCheck[i][j]=='x')&&
				(gRowCheck[i][j]==gRowCheck[i][j%4])
			)
			{

				cout <<"Array element is " <<gRowCheck[i][j] << endl;
			}
		}
	}

}
