#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <float.h>
using namespace std;

int main(int argc, char *argv[])
{
	float fParam=0.0;
	int iCount=0;
	float fSum=0;
	float fMax=-100000.0;
	float fMin=100000.0;
	float fAverage=0.0;
	//cout << "Enter a number" << endl;
	//scanf("%d",&iParam);
	//cout << "Value of our parameter: " << iParam << endl;

	/*while((scanf("%d",&iParam))
	{
		iCount++;
	}*/
	/*for(int i=0;i<15;i++)
	{
		cout << i;
	}*/
	while(iCount<15)
	{
		//cout << "Before increment: " << iCount << endl;

		scanf("%f",&fParam);
		/*if(fMax<fParam)
		{
			fMax=fParam;
		}
		if(fMin>=fParam)
		{
			fMin=fParam;
		}*/

		fSum+=fParam;


		/*
			Our initial value of fMax is a negative number
			as a result we need to use the < operator
			because we want to replace fMax if our current number [i.e fParam]
			is greater than it, same analogy applies to fMin except
			we need to use the > operator. 
		*/
		if(fMax<fParam) // our initial value of fMax is a negative 
		{
			//cout << "Inside fMax if " << endl;
			fMax=fParam;
		}
		if(fMin>fParam)
		{
			//
			//cout << "Inside fMin if " << endl; 
			fMin=fParam;
		}
		iCount++;

		//cout<<"After increment: "  <<iCount << endl;
	}
	fAverage=fSum/15.0;
	cout << "Value of max is: " << fMax << endl;
	cout << "Value of min is: " << fMin << endl;
	cout << "The average is: " << fAverage << endl;
	//cout<<"Value of sum is: " << iSum << endl;
	cout <<"Amount of items in our dataset is: " <<iCount << endl;
	//cout <<"value of count is: " <<iCount << endl;

	return 0;
}
