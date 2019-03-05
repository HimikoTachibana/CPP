#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static void bail(const char *on_what)
{
	fputs(on_what,stderr);
	fputc('\n', stderr);
}


int main(int argc, char *argv[])
{
	int z;
	struct sockaddr_in adr_inet;
	int len_inet;
	int sck_inet;

	sck_inet = socket(AF_INET,SOCK_STREAM,0);

	if( sck_inet == -1)
	{
		bail("socket()");
	}
	memset(&adr_inet,0,sizeof(adr_inet));

	adr_inet.sin_family = AF_INET;
	adr_inet.sin_port = htons(9000);

	if( !inet_aton("127.0.0.23",&adr_inet.sin_addr))
	{
		bail("bad address. ");
	}

	len_inet = sizeof(adr_inet);
	z= bind(sck_inet, (struct sockaddr *)&adr_inet,len_inet);

	if(z==-1)
	{
		bail("bind()");
	}

	system("netstat -pa --tcp 2>/dev/null");
	return 0;
}
