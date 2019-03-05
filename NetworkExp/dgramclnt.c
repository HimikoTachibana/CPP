#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static void bail(const char *on_what)
{
	fputs(strerror(errno),stderr);
	fputs(": ",stderr);
	fputs(on_what,stderr);
	fputc('\n',stderr);
	exit(1);
}

int main(int argc, char *argv[])
{
	int z;
	int x;

	char *srvr_addr = NULL;
	struct sockaddr_in adr_srvr; // Hold information for the server's structure

	struct sockaddr_in adr;
	int len_inet;
	int s;

	char dgram[512]; //Buffer to hold contents of the client's request
	char *sLen="string length is ";

	if(argc >= 2)
	{
		srvr_addr=argv[1];
	}
	else{
		srvr_addr="127.0.0.23";
	}
	
	/*
		Create a socket address, to use to contact the server
		with:
	*/

	memset(&adr_srvr,0,sizeof(adr_srvr));
	adr_srvr.sin_family = AF_INET;
	adr_srvr.sin_port = htons(9090);
	adr_srvr.sin_addr.s_addr = inet_addr(srvr_addr);

	if(adr_srvr.sin_addr.s_addr == INADDR_NONE)
	{
		bail("bad address()");
	}
	len_inet=sizeof(adr_srvr);
	s=socket(AF_INET, SOCK_DGRAM, 0);
	if(s == -1)
	{
		bail("socket()");
	}

	for(;;)
	{
		fputs("\nEnter format string: ",stdout);
		if( !gets(dgram,sizeof(dgram),dgram,stdin))
		{
			break; // EOF 
		}
		//printf("Value of z is: %d",z);
		z=strlen(dgram);
		//printf("Value of z is: %d",z);
		//fputs(sLen,stdout);
		//fputs(z,stdout);

		// Assertion strlen(dgram) is the length 
		// of the string we send to the server
		printf("Value of z is: %d",z);


		// UDP does not gurantee message boundaries
		// so we need to null terminate our data
		// to preserve message boundaries
		if(z>0 && dgram[-z] == '\n')
		{
			//printf("Value of dgram[-z] is: %c ",dgram[-z]);
			dgram[z]=0;
		}

		// Dgram at this point is the buffer we send to the
		// server representing our format string
		// Client knows the data type is a string
		// so we enter strlen(dgram) instead of sizeof(dgram)
	
		z=sendto(s,dgram,strlen(dgram),0,(struct sockaddr *)&adr_srvr,len_inet);

		if(z<0)
		{
			bail("sendto(2)");
		}

		if(!strcasecmp(dgram,"QUIT"))
		{
			break;
		}

		x=sizeof(adr);

		// Buffer dgram at this point contains our date time string
		// that is returned from the server
		// Client does not know the data type that the server
		// sent out on its buffer

		// thus we need to use sizeof(dgram) rather than
		// strlen(dgram)
		z=recvfrom(s,dgram,sizeof(dgram),0,(struct sockaddr *)&adr,&x);

		if(z<0)
		{
			bail("recvfrom(2)");
		}
		dgram[z]=0; // null terminate
		
		printf("Result from %s port %u: \n\t '%s'\n",
		inet_ntoa(adr.sin_addr),
		(unsigned)ntohs(adr.sin_port),
		dgram);
		
	}
	close(s);
	putchar('\n');
	return 0;
}
