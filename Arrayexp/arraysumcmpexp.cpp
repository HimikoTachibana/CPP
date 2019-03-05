#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>

using namespace std;

int merge(int arr[], int leftPos, int midpoint, int rightEnd);

int mergeSortD(int arr[],int left, int right);

int mergesort(int arr[], int len);

bool intersect(int arrEin[],int arrZwei[], int m, int n);

int merge(int arr[], int leftPos, int midpoint, int rightEnd)
{
	int iCounter=0;
	int iNumElements=rightEnd-leftPos+1;

	int *pArr = new int[iNumElements];

	if(pArr!=NULL)
	{
		int iLeftBeg=leftPos;
		int iLeftEnd=midpoint;
		int iRightBeg=midpoint+1;
		int iRightEnd=rightEnd;

		int iDx=leftPos;

		while((iLeftBeg <= iLeftEnd) && (iRightBeg <= iRightEnd))
		{
			if(arr[iLeftBeg] <= arr[iRightBeg])
			{
				//We perform iDx-leftPos instead
				// of iDx-leftPos because our loop started
				// at the leftposition of the array
				// rather than 0 so if we did iDx instead
				// of iDx-leftPos, we would run into memory leaks

				pArr[iDx-leftPos]=arr[iLeftBeg];
				
				iLeftBeg++;
				iDx++;
			}
			else
			{
				pArr[iDx-leftPos]=arr[iRightBeg];
				iRightBeg++;
				iDx++;
			}
		}
		if(iLeftBeg<=midpoint)
		{
			//Copy rest of the left part of the array back
			while(iLeftBeg <= iLeftEnd)
			{
				pArr[iDx-leftPos]=arr[iLeftBeg];
				iLeftBeg++;
				iDx++;
			}
		}
		if(iRightBeg<=rightEnd)
		{
			//Copy rest of right subarray back
			while(iRightBeg<=iRightEnd)
			{
				pArr[iDx-leftPos]=arr[iRightBeg];
				iRightBeg++;
				iDx++;
			}
		}
		for(iDx=leftPos;iDx<=rightEnd;iDx++)
		{
			arr[iDx]=pArr[iDx-leftPos];
		}
		delete [] pArr;
		pArr=NULL;
	}
	else
	{
		throw runtime_error("Error when allocating memory in Merge function");
	}

	return iCounter;
}

int mergeSortD(int arr[],int left, int right)
{
	int iBarom=0;

	if(left < right)
	{
		int iMid=left+(right-left)/2;
		iBarom+=mergeSortD(arr,left,iMid);
		iBarom+=mergeSortD(arr,iMid+1,right);
		iBarom+=merge(arr,left,iMid,right);
	}
	return iBarom;
}


int mergesort(int arr[],int len)
{
	int iCount=0;

	if((NULL != arr) || (len>=0))
	{
		iCount+=mergeSortD(arr,0,len-1);
	}
	else
	{
		throw runtime_error("Invalid argument passing to MERGESORT function!!!");

	}
	return iCount;
}

//int mergesortD(int arr[], int iLen
void printarr(int arr[], int len)
{
	for(int i=0;i<len;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//Implementation note: variabe m is len of arrEin, n is len of arrZwei

bool intersect(int arrEin[], int arrZwei[],int m, int n)
{
	int i=0;
	int j=0;
	bool bFound=false;
	while((i<m && j<n))
	{

		//cout <<"Value of i is: "<<i<<" Array element is: " <<arrEin[i] << endl;
		//cout <<"Value of j is: " <<j <<"Array element is: " <<arrZwei[j] << endl;
		
		if(arrEin[i]<arrZwei[j])
		{
			i++;
		}
	
		if(arrEin[i]>arrZwei[j])
		{
			j++;
		}
		if(arrEin[i]==arrZwei[j])
		{
			cout << arrEin[i] << endl;
			//cout << arrZwei[j] << endl;
			bFound=true;
			i++;
			j++;
		}
			//i++;
			//j++;
	}
	return bFound;
}


int main(int argc, char *argv[])
{
	//int arr[4]={4,5,9,8};

	int *p= new int[4];
	
	p[0]=4;
	p[1]=5;
	p[2]=9;
	p[3]=8;


	int iSum=14;

	int *iOffsetArr=new int[4];



	for(int j=0;j<4;j++)
	{
		iOffsetArr[j]=iSum-p[j];
	}

	for(int k=0;k<4;k++)
	{
		cout << "Value of k is: " << k << " it's index element is: " << iOffsetArr[k] << endl;
	}
	/*for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			//cout << "Value of i is " <<i <<endl;
			//cout << "Value of j is " << j << endl;

			if(i<=j)
			{
				cout << "Value of i is " << i << endl;
				cout << "Value of j is " << j << endl;
				cout << arr[i] << endl;
				cout << arr[j] << endl;
			}
			//cout << arr[i] << endl;
			//cout << arr[j] << endl;
		}
	}*/
	mergesort(p,4);
	mergesort(iOffsetArr,4);

	cout << "printing p array" << endl;
	printarr(p,4);
	cout << "printing iOffsetArr" << endl;
	printarr(iOffsetArr,4);


	bool bFound=false;
	bFound=intersect(p,iOffsetArr,4,4);


	if(bFound == true)
	{
		cout << "If executed "<<bFound << endl;
	}
	//cout << "Flag value is: " << bFound << endl;
	/*bool bFound=false;
	for(int r=0;r<4;r++)
	{
		//cout << iOffsetArr[r] << endl;

		if((iOffsetArr[r]==p[r]))
		{
			cout << iOffsetArr[r] << endl;
			bFound=true;
		}
	}*/
}
