#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int z;
	int sck_inet;
	struct sockaddr_in adr_inet;
	int len_inet;

	sck_inet = socket(AF_INET, SOCK_STREAM,0);

	printf("Value of sck_inet is:  %d\n",sck_inet);

	if(sck_inet == -1)
	{
		abort();
	}

	memset(&adr_inet,0,sizeof(adr_inet));
	adr_inet.sin_family = AF_INET;
	adr_inet.sin_port = htons(9000);

	int iR=inet_aton("192.168.1.76",&adr_inet.sin_addr);
	printf("Value of iR is %d: ",iR);
	//adr_inet.sin_addr.s_addr=ntohl("192.168.0.1");
	if(iR==0)
	{
		abort();
	}
	len_inet = sizeof(adr_inet);
	printf("Length of inet is: %d", len_inet);
	z=bind(sck_inet,(struct sockaddr*)&adr_inet,len_inet);
	printf("The value of bind is: %d ", z);
	if(z== -1)
	{
		perror(errno);
		abort();
	}
	printf("Made through all the steps\n");
	close(sck_inet);
	return 0;
}
