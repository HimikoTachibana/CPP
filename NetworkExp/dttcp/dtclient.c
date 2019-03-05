#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


/*
	Helper function that posts error information
*/
static void bail(const char *on_what)
{

	// We need to post both the errno so we can obtain the reason
	// for the error and the function that caused it.
	fputs(strerror(errno),stderr);
	fputs(": ",stderr);

	fputs(on_what,stderr);
	fputc('\n',stderr);
	exit(1);
}

int main(int argc, char *argv[])
{
	int z;
	char *srvr_addr=NULL;
	char *srvr_port = "9090";
	struct sockaddr_in adr_srvr;
	int len_inet;
	int s;

	struct servent *sp;
	char dtbuf[128];

	if(argc >= 2)
	{
		srvr_addr=argv[1];
	}
	else{
		srvr_addr = "127.0.0.1";
	}

	//printf("%s\n",srvr_addr);

	if(argc >= 3)
	{
		srvr_port = argv[2];
	}

	s=socket(PF_INET,SOCK_STREAM,0);
	//fprintf(stdout,"%d\n",s);
	if(s==-1)
	{
		bail("socket()");
	}

	
	//fprintf(stdout,"%d",s);


}
