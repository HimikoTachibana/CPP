#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

void bail(const char *on_what)
{
	fputs(on_what,stderr);
	fputs(": ",stderr);
	fputs(strerror(errno),stderr);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	FILE *fptr;
	fptr=fopen("input.txt","r+");
	int iStringLengthNaught=6; // think calculus notation
	int iSeekRet=0;
	
	char ch;

	if(fptr == NULL)
	{
		bail("fopen()");
	}

	int iCharcount=0;

	char *sPtr = (char *)malloc(iStringLengthNaught*sizeof(char));

	if(sPtr == NULL)
	{
		bail("malloc()");
	}
	//while(((ch=getc(fptr))!= '\n')&&((ch=getc(fptr)) != EOF))
	//{
		//if(ch != '\n')
		//{
			//printf("%c",ch);
		//}
		//printf("%c\n",ch);
		//iCharcount++;
	//}

	//while((  (ch=getc(fptr))  != '\n')&&( (ch = getc(fptr)) != EOF))
	//ch = getc(fptr);
	int iLineCount=0; // variable that stores the amount of lines in the file
	
	int iSkipcount=0; // variable that represents the amount of characters
	// in each line
	while( ( ch = getc(fptr) ) != EOF) 
	{
		//ch=getc(fptr);
		//iCharcount=0;
		iSkipcount=0;
		printf("\n %c ",ch); // This printf is inserted here to
		printf("\n");
		printf("iSkipcount value is: %d\n",iSkipcount);
		// compensate for off by 1 iterations for the first
		// character in the string
		while ( (ch = getc(fptr) ) != '\n')
		{
			printf("\t");
			printf("\n %c",ch);
			printf("\n");
			iSkipcount++;
			printf("iSkipcount value is: %d\n ",iSkipcount);
			iCharcount++;
			//iSkipcount=0;
		

		}
		iSkipcount++;
		iLineCount++;
		iCharcount++;

	
		printf("\n");
		printf("iSkipcount is: %d \n",iSkipcount);
		//for(int i=0;i<iSkipcount;i++)
		//{
			//printf("Value of i is : %d\n",i);
			//printf("%c",ch);
		//}
		printf("iLineCount is: %d \n",iLineCount);
		printf("iCharCount is: %d \n",iCharcount);
		printf("\n");
		//iCharcount=0;
	}
	
	// Rewind file pointer back to sector 0
	iSeekRet=fseek(fptr,0,SEEK_SET);

	if(iSeekRet == -1)
	{
		bail("fseek()");
	}


	
	/*while( (ch=getc(fptr) ) != EOF)
	{
	}*/
	// Allocate an array of size linecount

	
		/*while( ( ch=getc(fptr) ) != '\n') 
		{
		//printf("%c\n",ch);

		//if(ch != '\n')
		//{
			printf("%c",ch);
		//}
			iCharcount++;
		//printf("\n");
		}
		printf("\n");*/
	//ch=getc(fptr);

	//while((ch!='\n')&&(ch!=EOF))
	//{
		//iCharcount++;
	//}
	printf("The value of iSkipCount is: %d \n",iSkipcount);
	printf("There are %d lines in the file\n",iLineCount);
	printf("Amount of characters in total is %d\n",iCharcount);
	fclose(fptr);
	return 0;
}
