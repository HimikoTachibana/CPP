#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
	int status=-1;
	int iArgs=0;

	char buf[argc];

	//for(iArgs=1;iArgs>argc;++iArgs)
	//{
		//printf("%s\n",argv[iArgs]);
		//buf[iArgs]=argv[iArgs];
		//if(iArgs>4)
		//{
			//printf("Too much args");
			//exit(2);
		//}
	//}

	/*for(int i=1;i>argc;i++)
	{
		printf("%s\n",buf[i]);
	}*/
	printf("%d\n",argc);
	
	for(int i=1;i<argc;i++)
	{
		printf("value at i %d is '%s' \n",i,argv[i]);
	}
	//printf("%s\n",argv[2]);
}
