#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define _GNU_SOURCE
extern int h_errno;

int main(int argc, char *argv[])
{
	int x;
	int y;
	struct hostent *hp;

	for(x=1;x<argc;++x)
	{
		hp=gethostbyname(argv[x]);
		if(!hp) //host entry not found in any DNS resolver's database
		{
			fprintf(stderr,"%s: host '%s'\n",hsterror(h_errno),argv[x]);
			continue;
		}
		printf("Host %s :\n",argv[x]);
		printf(" Officially:\t%s\n",hp->h_name);
		fputs(" Aliases:\t",stdout);
		for(y=0;hp->h_aliases[y];++y)
		{
			if(y)
			{
				fputs(" ,",stdout);
			}
			fputs("Alias list: ",stdout);
			fputs(hp->h_aliases[y],stdout);
		}
		fputc('\n',stdout);
		printf(" Type:\t\t%s\n",hp->h_addrtype == AF_INET ? "AF_INET" : "AF_INET6");
		if(hp->h_addrtype == AF_INET)
		{
			for(y=0;hp->h_addr_list[y];++y)
			{
				printf(" Address:\t%s\n", inet_ntoa(*(struct in_addr *)hp->h_addr_list[y]));
			}
			putchar('\n');
		}
	}
	return 0;
}
