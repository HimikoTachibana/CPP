#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	int iTemp=0;
	vector<int> vDummy;
	int iSum=0;
	int iAverage=0;
	int iCount=0;

	string sStop="";
	//cin >> sStop;
	bool bStopped=false;
	while(bStopped != true)
	{
		//cin >> sStop;
		//cout << "Value of sStop: " << sStop << endl;
		//cout << "The value of stop: " << sStop << endl;
		//if(sStop=="stop")
		//{
			//cout << "Inside of stop if" << endl;
			//break;
		//}
		cout << "Dummy array size is" << vDummy.size() << endl;
		while(cin>>iTemp)
		{
			cout <<"Value of iTemp: " << iTemp << endl;
			vDummy.push_back(iTemp);
			iSum+=iTemp;
			iCount++;
			cout << "The value of iCount is: " << iCount << endl;
			iAverage=iSum/iCount;
			
			cout <<"The average is: " <<iAverage << endl;
			cout << "Value of bStopped is: " << bStopped << endl;
			bStopped=false;
			//vDummy.push_back(iTemp);
			//cout << vDummy.size() << endl;
		}


		cout << "Test print" << endl;
		//cout << "Value of bStopped is: " <<bStopped << endl;
		//if(bStopped == true)
		//{
			
		//}
		//if(sStop=="stop")
		//{
			//break;
		//}
		//cin >> sStop;
		//if(iTemp == EOF)
		//{
			//cout << "Size of dummy vector is: " << vDummy.size() << endl;
		//}
		//cout << "Size of dummy vector is " << vDummy.size() << endl;
		//cout << "Value of bStopped: " << bStopped << endl;
		//bStopped=true;
		//cout << "Test printing" << endl;
		//bStopped=true;
	}
	//cout << vDummy.size() <<endl;
	return 0;
}
