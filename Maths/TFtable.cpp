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
	
	for(int i=0;i<iRows;i++) // loop through all the rows 
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
		if(iVecSize==0)
		{
			cout << "Inside iVecSize == 0 if: "<<endl;
			//cout << 0 << 0 << 0 << endl;
			cout << iVecSize << endl;

			// We need to append three 0s to accomdate for 0 padding
			for(int q=0;q<3;q++)
			{
				vExpVec[i].push_back(0);
			}
			cout <<"Vector size when i is 0: " << vExpVec[i].size() << endl;
			for(int jj=0;jj<vExpVec[i].size();jj++)
			{
				cout<<vExpVec[i][jj] << endl;
			}

		}
		if(iVecSize == 1 )
		{
			// TO DO: Zero padding to obtain 001
			cout << "inside iVecSize == 1 if" <<endl;
			for(int z=0;z<vExpVec[i].size();z++)
			{
				cout << "The value of i is: " << i << endl;
				cout << "The value of z is: " << z << endl;
				cout << 0 << 0 << vExpVec[i][z] << endl;
			}

			//vExpVec[i].push_back(0);
			//vExpVec[i].push_back(0);
			//vExpVec[1][1]=0;


			vExpVec[1].push_back(0);
			vExpVec[1].push_back(0);
			cout<< "Size of vExpVec[i].size()" << vExpVec[i].size() << endl;
			for(int kk=0;kk<vExpVec[i].size();kk++)
			{
				cout << vExpVec[i][kk] << endl;
			}

		}

		if(i==2 || i==3)
		{
			cout << "inside i==2 || i==3 if " << endl;
			cout << "The size of vectors inside the if: " << vExpVec[i].size() << endl;
			for(int t=0;t<vExpVec[i].size();t++)
			{
				//vExpVec[i][0]=0;
				//vExpVec[i][1]=0;
				cout << vExpVec[i][t] << endl;
			}
			vExpVec[i].push_back(0);
			cout <<"----"<<vExpVec[i].size() << "After loop size" << endl;

			for(int g=0;g<vExpVec[i].size();g++)
			{
				cout << vExpVec[i][g] << endl;
			}
		}

		for(int r=0;r<vExpVec[i].size();r++)
		{
			
			cout << "value of i: " << i << " value of r: " << r << " value of that particular element: " <<vExpVec[i][r] << endl;
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

	// Loop to sanity check if all the column vectors are of size 3

	for(int y=0;y<iRows;y++)
	{
		//cout << "Size of each column vector at y:  "<<y << " is: " << vExpVec[y].size() << "\n";
		cout << "The value of y is: " << y << endl;
		for(int iColIdx=3; iColIdx>0;iColIdx--)
		{
			//cout << "For debugging we print out the column index to the console: " << iColIdx << endl;
			//cout << "Value of y is: " << y << endl;
			//cout << "Value of col index - 1 is: " << iColIdx-1 << endl;
			cout << vExpVec[y][iColIdx-1] << endl;
		}
	}

	//cout <<"Vector size: " <<vExpVec.size() << endl;
	





	return 0;
}
