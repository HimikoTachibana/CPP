#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	int i=0;
	vector<int> vBucket;
	int iTemp=0;

	for(i=0;i<5;i++)
	{
		cin>>iTemp;
		vBucket.push_back(iTemp);
	}


	int iSum=0;
	for(int j=0;j<vBucket.size();j++)
	{
		//cout <<"We are at iteration number: " <<j<<" "<<vBucket[j] << endl;
		iSum+=vBucket[j];
		
	}
	cout << iSum << endl;
	cout <<"Average is: " <<iSum/vBucket.size() << "\n";
	return 0;
}
