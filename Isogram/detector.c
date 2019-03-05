#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>


void mergsort(char *arr, int len);
void mergesortD(char *arr, int left, int right);
void merge(char *arr,int leftPos, int midpoint, int rightPos);
/*Initializes all elements in the array to a*/
void initialize(char *cArr, int iLen)
{
	for(int i=0;i<iLen;i++)
	{
		cArr[i]='a';
	}

}
void printelements(char *cArr, int iLen)
{
	for(int i=0;i<iLen;i++)
	{
		printf("%c\n",cArr[i]);
	}

}

int CountChar(char *cArr, int iLen, char searchKey)
{
		int iCount=0;
		for(int i=0;i<iLen;i++)
		{
			if(cArr[i]==searchKey)
			{
				//printf("cArr[i] %c\n",cArr[i]);
				iCount++;
			}
		}
		return iCount;
}

void sort(char *cArr, int iLen)
{

	/*if(( NULL != cArr) && (iLen>=0) )
	{
		int j=-1;
		char cKey;
		int i=-1;
		for(int iGap=iLen/2;iGap>0;iGap/=2)
		{
		
			cKey=cArr[j];
			i=j-iGap;
			printf("%c\n",cKey);
			while(( i>=(iGap-1)) && (cArr[i]>cKey) )
			{
				cArr[i+iGap]=cArr[i];
				i-=iGap;
			}
			cArr[i+iGap]=cKey;
		}
	}*/
	/*for(int i=0;i<iLen;i++)
	{
		
	}*/

	int i,j;
	char key;
	for(i=1;i<iLen;i++)
	{
		key=cArr[i];
		j=i-1;

		while(j>=0 && cArr[j] > key)
		{
			cArr[j+1]=cArr[j];
			j=j-1;
		}
		cArr[j+1]=key;
	}

}

void sortint(int *arr, int len)
{
	int i,j;
	int key;
	for(i=1;i<len;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>=key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}


void merge(char *arr, int leftPos, int midpoint, int rightEnd)
{
	int iCounter=0;
	int iNumElements = rightEnd-leftPos+1;
	char *pArr=(char *)malloc(iNumElements*sizeof(char));

	if(pArr != NULL)
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
			while(iLeftBeg<=iLeftEnd)
			{
				pArr[iDx-leftPos]=arr[iLeftBeg];
				iLeftBeg++;
				iDx++;
			}
		}

		if(iRightBeg<=rightEnd)
		{
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
		if(pArr != NULL)
		{
			free(pArr);
		}
		pArr=NULL;
	}
}


void mergeSortD(char *arr, int left, int right)
{
	if(left<right)
	{
		int iMid=left+(right-left)/2;
		mergeSortD(arr,left,iMid);
		mergeSortD(arr,iMid+1,right);
		merge(arr,left,iMid,right);
	}
}


void mergesort(char *arr, int len)
{
	if(( arr != NULL) || (len>=0) )
	{
		mergeSortD(arr,0, len-1);
	}
}



int main(int argc, char *argv[])
{
	const int iSigChars=10;
	char *sTest=(char *)malloc(iSigChars*sizeof(char));
	initialize(sTest,iSigChars);
	//printelements(sTest,iSigChars);
	

	if(sTest == NULL)
	{
		printf("Failed to allocate memory:");
		exit(EXIT_FAILURE);
	}
	//scanf("%c\n",&sTest[0]);
	//for(int i=0;i<iSigChars;i++)
	//{
		//printf("Enter a character\n");
		//fscanf(stdin,"%c\n",sTest[i]);
		/*if(i<iSigChars)
		{
			scanf("%c\n",&sTest[i]);
			fflush(stdin);
		}*/
		//scanf("%c\n",&sTest[i]);
		//printf("%d\n",i);
		//scanf("%c\n",&sTest[i]);
		//fflush(stdin);
	//}
	int i=0;
	//while(i<iSigChars)
	//{	//i++;
		//scanf("%c\n",&sTest[i]);
		//i++;
		//i++;
	//}
	bool bTerm=false;
	do{
		if(i==iSigChars-1)
		{
			//bTerm=true;
			printf("This input will not be in the input string\n");
			//break;
		}
		scanf("%c\n",&sTest[i]);
		i++;
	}while(i<iSigChars);

	
	
	printf("Elements are: \n");
	printelements(sTest,iSigChars);
	
	printf("Calling the mergesort function \n");
	int iCount=0;
	//sort(sTest,iSigChars);
	mergesort(sTest,iSigChars);
	//printf("\nSorted array :\n ");
	printelements(sTest,iSigChars);
	//iCount=CountChar(sTest,iSigChars,'a');
	/*for(int j=0;j<iSigChars;j++)
	{

		for(int k=0;k<iSigChars;k++)
		{
			iCount=CountChar(sTest,iSigChars,sTest[j]);
		}
	}*/

	// TO DO: Put this in a wrapper function
	int iDupTracker=0;
	for(int i=0;i<iSigChars;i++)
	{
		if(sTest[i]==sTest[i+1])
		{
			iDupTracker++;
			printf("value of i is: %d\n",i);
			printf("Value at that index is: %c\n",sTest[i]);
		}
	}
	printf("Value of iDupTracker: %d\n",iDupTracker);
	char *cTemp=(char *)malloc(iSigChars*sizeof(char));
	initialize(cTemp,iSigChars);
	
	int iDupiDx=0; // variable to keep track of location of
	// current duplicate
	for(int j=0;j<iSigChars;j++)
	{
		if(sTest[j]!=sTest[j+1])
		{
			//iDupiDx=j;
			iDupiDx++;
			//printf("Value of j is: %d\n",j);
			printf("Value of duplicate tracker index is: %d\n",iDupiDx);
			cTemp[iDupiDx]=sTest[j];
		}
		//iDupiDx++;
		//cTemp[iDupiDx]=sTest[j];
		
	}
	//iDupiDx++;
	printf("iDupiDx: %d\n",iDupiDx);
	printf("iSigChars-1 %d\n",iSigChars-1);
	//printf("cTemp value at iDupiDx is: %c\n ",cTemp[iDupiDx]);
	//printf("sTest value at iSigChars-1: %c\n ",sTest[iSigChars-1]);
	// place last known non duplicate at the end off the array
	cTemp[iDupiDx]=sTest[iSigChars-1];
	printf("iDupiDx: %d\n",iDupiDx);
	// We use CTemp+1 so we can start the iteration from the first element
	// of CTemp
	printelements((cTemp+1), iDupiDx);

	printf("\n");
	printf("\n");
	for(int i=1;i<iDupiDx+1;i++)
	{
		printf("%c\n",(cTemp[i]));
	}
	/*for(int j=0;j<iSigChars;j++)
	{
		
		if(sTest[j]==sTest[j+1])
		{
			//iDupTracker=j;
			//j++;
			//cTemp[j]=sTest[j];
			iDupTracker++;
			printf("%d\n",j);
			printf("%c\n",sTest[j]);
			printf("Value of duplicate tracker is: %d\n",iDupTracker);
		}
		//cTemp[iDupTracker++]=sTest[j];
		//j++;
		//cTemp[j]=sTest[j];
	}*/
	
	/*for(int k=0;k<iSigChars;k++)
	{
		printf("cTemp[%d]: %c\n",k,cTemp[k]);
	}*/
	/*for(int i=0;i<iSigChars;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(sTest[i]==sTest[j])
			{
				//printf("%c\n",sTest[
				iCount++;
				//iCount=0;
			}
			printf("Value of iCount %d, %c\n",iCount,sTest[i]);
			iCount=0;
		}
	}*/
	//for(int i=0;i<iSigChars;i++)
	//{
	//}
	//printf("Value of iCount is: %d\n",iCount);

	int *iCountArray=(int *)malloc(iDupiDx+1*sizeof(int));
	for(int i=0;i<iDupiDx+1;i++)
	{
		iCountArray[i]=0;
	}

	//iCountArray[0]++;
	//printf("iCountArray[0] :%d\n",iCountArray[0]);
	int iCounter=0;
	for(int i=0;i<iSigChars;i++)
	{
		//printf("%c ",sTest[i]);
		for(int j=1;j<iDupiDx+1;j++)
		{
			if(sTest[i]==cTemp[j])
			{
				iCountArray[j-1]++;
				//printf("i: %d\n",i);
				//printf("j: %d\n",j);
				//printf("sTest[i]: %c\n",sTest[i]);
				//printf("cTemp[j]: %c\n",cTemp[j]);
				//iCounter++;
				//printf("If executed");
			}
			//printf("Value of counter is: %d\n",iCounter);
			//iCounter=0;
			//printf("Value of i is: %d\n",i);
			//printf("Value of j is: %d\n",j);
			//printf("Value of arr[i] is: %c\n",sTest[i]);
			//printf("Value of arr2[j] is: %c\n",cTemp[j]);
			
		}
	}
	for(int k=0;k<iDupiDx;k++)
	{
		printf("%d\n",iCountArray[k]);
	}
	sortint(iCountArray,iDupiDx);
	for(int p=0;p<iDupiDx;p++)
	{
		if( (iCountArray[0] == iCountArray[i]) && (iCountArray[i]==iCountArray[i+1])    ){
			printf("Our string is an isogram");
		}
	}
	//printf("iCount value is: %d\n",iCounter);
	//printf("\n");


}
