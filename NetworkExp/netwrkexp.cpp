#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
using namespace std;

static void bail(const char *on_what)
{
	perror(on_what);
	exit(1);
}

int main(int argc, char *argv[], char **envp)
{
	int z; // status return code 
	int sck_inet; // Socket 

	struct sockaddr_in adr_inet; // AF_INET;
	int len_inet; // variable to store the size of our address structure

	const unsigned char IPno[]={127.0,0,1};

	/*Create an ipv4 Socket*/

	sck_inet = socket(AF_INET, SOCK_STREAM, 0);

	if(sck_inet == -1)
	{
		bail("socket()");
	}

	/*Create an AF_INET address*/
	memset(&adr_inet,0,sizeof(adr_inet));

	adr_inet.sin_family = AF_INET;
	adr_inet.sin_port = htons(9000);
	memcpy(&adr_inet.sin_addr.s_addr,IPno,4);
	len_inet = sizeof(adr_inet);


	/*
		Bind address to the socket i.e associate the address structure
		to the file descriptor, put differently we now have an <fd,address> pair
		where the fd is an integer and the address is of type struct
	*/

	z=bind(sck_inet,(struct sockaddr *)&adr_inet,len_inet);

	if(z==-1)
	{
		bail("bind()");
	}
	
	system("netstat -pa -- tcp 2>/dev/null ");
	close(sck_inet);
	return 0;
}
