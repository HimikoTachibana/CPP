#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>

void bail(const char *on_what)
{
	fputs(on_what,stderr);
	fputs(": ",stderr);
	fputs(strerror(errno),stderr);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	int iLengthNaught=8;
	char *cPtr=(char *)malloc(iLengthNaught*sizeof(char));
	if(cPtr == NULL)
	{
		bail("malloc()");
	}
	for(int i=0;i<iLengthNaught;i++)
	{
		cPtr[i]=0;
	}

	for(int j=0;j<iLengthNaught;j++)
	{
		cPtr[j]='a';

	}

	for(int k=0;k<iLengthNaught;k++)
	{
		printf("%c",cPtr[k]);
	}
	printf("\n");

}
