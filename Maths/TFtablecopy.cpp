#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <typeinfo>
using namespace std;


/*
	Function that takes as an integer as a parameter
		the number that the user wants to convert into binary
	Return type: A vector containing all of the bits that are used
	to convert from decimal to binary
*/

vector<int> BitVectoDectoBin(int iParam)
{
	vector<int> bTestVec;
	int i=iParam;
	while(i>0)
	{
		bTestVec.push_back(i%2);
		i/=2;
	}
	return bTestVec;

}


/*
	Function that returns nothing:
		Takes as parameter a vector loops through 
		all the elements and prints them out
*/
void PrintVec(vector<int> iVecParam)
{
	int iSize=iVecParam.size();
	for(int i=0;i<iSize;i++)
	{
		cout << "vec[" << i << "]" <<" " <<iVecParam[i] << endl;
	}
}

// Function that returns the length of a vector
/*int VectorLength(vector<int> iVecParam)
{
	int iSize=iVecParam.size();
	return iSize;
}*/


int main(int argc, char *argv[])
{


	/*

	*/
	int a=8;
	int iMain=7;
	int iVecSize=0;
	vector<int> bVec;

	int iRows=8;
	int iCols=3;
	vector<vector<int> > bitVec2D(iRows, vector<int>(iCols));
	vector<vector <int> > vExpVec(iRows);
	//vector<int> vColExp(iCols);

	//vColExp.push_back(0);
	//vColExp.push_back(0);
	//vColExp.push_back(0);
	
	for(int i=0;i<iRows;i++)
	{
		//cout << i << bitVec2D[i].size() << endl;
		//cout <<" " <<i << vExpVec[i].size() << endl;
		vExpVec[i]=BitVectoDectoBin(i);
		//cout << vExpVec[i].size() << endl;
		cout << "The value of i is: " << i << endl;


		int iVecSize=vExpVec[i].size();
		cout <<"The value of iVecSize: " <<iVecSize << endl;

		/*if(iVecSize==0)
		{
			cout
		}*/
		
		vector<int> vDummy;
		if(iVecSize == 1 | iVecSize == 0)
		{
			cout << "inside iVecSize == 1 or iVecSize == 0 if: " <<endl;
			for(int z=0;z<vExpVec[i].size();z++)
			{
				cout << 0 << 0 << vExpVec[i][z] << endl;
			}
		}

		for(int r=0;r<vExpVec[i].size();r++)
		{
			cout << vExpVec[i][r] << endl;
		}
		/*bVec=BitVectoDectoBin(i); //1
		//vExpVec[i]=bVec;
		vector<int> tmp; //=vExpVec[i]; //c
		//out<<"vExpVec's type: " <<typeid(vExpVec[i]).name() << endl;
		//cout << typeid(bVec).name() << endl;
		vExpVec.push_back(bVec); //2
		cout << "Size of vExpVec i is: " << bVec.size() << endl; //3
		for (auto iOneN:bVec) //4
		{//
			tmp.push_back(iOneN);//5
		}//
		*/	//tmp.push_back(iOneN);

		//bVec.clear(); //6
	
	}

	//for(int j=0;j<iRows;j++)
	//{
		//cout << vExpVec[j] << endl;
	//}
	//cout << vExpVec.size() << endl;
	





	return 0;
}
