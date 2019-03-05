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
	fputs("\n",stderr);
	exit(1);
}


int main(int argc, char *argv[])
{
	int z;
	char *srvr_addr = NULL;
	struct sockaddr_in adr_inet; //AF_INET
	struct sockaddr_in adr_clnt; //AF_INET
	int len_inet; //length
	int s; //Socket
	char dgram[512];
	char dtfmt[512];
	time_t td;
	struct tm tm;

	if(argc>=2)
	{
		srvr_addr=argv[1];
	}
	else
	{
		srvr_addr="127.0.0.23";
	}

	// Create a UDP socket to use
	s=socket(AF_INET,SOCK_DGRAM,0);
	if(s == -1)
	{
		bail("socket()");
	}
	int opt=1;
	if(setsockopt(s,SOL_SOCKET,SO_REUSEADDR| SO_REUSEPORT,&opt,sizeof(opt)))
	{
		bail("setsockopt");
	}



	// Create a socket address, for use with bind(2)
	memset(&adr_inet,0,sizeof(adr_inet)); 
	//See above:  We zero out the memory
	// contents to help in debugging when we peer into the socket
	// structures in its members
	adr_inet.sin_family = AF_INET;
	adr_inet.sin_port = htons(9090);
	adr_inet.sin_addr.s_addr = inet_addr(srvr_addr);

	if(adr_inet.sin_addr.s_addr == INADDR_NONE)
	{
		bail("bad address.");
	}
	len_inet = sizeof(adr_inet);

	z=bind(s,(struct sockaddr *)&adr_inet,len_inet);
	
	if(z == -1)
	{
		bail("bind()");
	}
	
	for(;;)
	{
		// Block until the program receives a datagram at our address
		// and port

		len_inet = sizeof(adr_inet);
		
		// Dgram at this point is the buffer we receive from the client
		// Notice that we invoke the function sizeof(dgram) insted of strlen(dgram)
		// because to the point of view of the server, the server does not
		// know the client's data is a string more generally
		// the server cannot infer the type of the client's data that was
		// sent out on the client's buffer

		z=recvfrom(s,dgram,sizeof(dgram),0,(struct sockaddr *)&adr_clnt, &len_inet);
		//printf("%d\n",z);
		if(z<0)
		{
			bail("recvfrom(2)");
		}


		// Process the request

		// We null terminate our data since UDP does not preserve
		// message boundaries, so we null terminate our data to
		// indicate to the server that our data is of size z bytes
		dgram[z]=0;

		//printf("%s\n",dgram);
		if( !strcasecmp(dgram,"QUIT"))
		{
			break;
		}

		// Get current date/time

		time(&td);
		tm = *localtime(&td);

		strftime(dtfmt,sizeof(dtfmt),dgram,&tm);

		//Send formatted date/time string to client

		z=sendto(s,dtfmt,strlen(dtfmt),0,(struct sockaddr *)&adr_clnt,len_inet);

		if(z<0)
		{
			bail("sendto(2)");
		}

	}
	close(s);
	return 0;
}
