#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
	int i=100;
	int iCount=0;

	while(i!=0)
	{
		//printf("%d\n",i%2);
		i/=2;
		iCount++;
	}
	printf("The value of iCount is: %d\n",iCount);
	int *iBitArray=(int *)malloc(iCount *sizeof(int));
	i=100;
	int iDx=0;
	if(iBitArray != NULL)
	{
		/*
			Initialize array elements to 0
		*/
		for(int j=0;j<iCount;j++)
		{
			iBitArray[j]=0;
		}
		
		/*Convert from dec to bin*/
		while( i!=0)
		{
			iBitArray[iDx]=i%2;
			i/=2;
			iDx++;
		}
		// Print bit vector out
		for(int k=iCount;k>0;k--)
		{
			printf("%d\n",iBitArray[k-1]);
		}

		free(iBitArray);
		iBitArray=NULL;
		

	}
	else{
		printf("Memory allocation failed...\n");
	}
	return 0;
}
