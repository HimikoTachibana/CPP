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
	int status = -1;
	struct addrinfo hints;
	struct addrinfo *res;
	struct addrinfo *ptr; // pointer to traverse our linked list of
	// results

	//int iHintsLen=sizeof(hints);

	memset(&hints,0,sizeof(hints));
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_STREAM;
	//hints.ai_protocol = 0;
	//hints.ai_flags = AI_PASSIVE;
	//hints.ai_canonname = NULL;
	//hints.ai_addr=NULL;
	//hints.ai_next=NULL;

	char *pstr="www.google.com";

	/*
		Obtain website i.e domainname from command line.
	*/

	if(argc>=2)
	{
		pstr=argv[1];
	}
	else{
		pstr="www.google.com";
	}
	status=getaddrinfo(pstr,"3490",&hints,&res);
	fprintf(stdout,"Value of status is: %d\n",status);
	//printf("Value of status is: %d\n",status);
	//if((status= getaddrinfo(NULL,"3490",&hints,&res)) !=0)
	if(status !=0)
	{
		fprintf(stdout,"%d\n",status);
		fprintf(stderr,"getaddrinfo system call failed :%s\n",gai_strerror(errno));
		exit(1);
	}

	char ip4[INET_ADDRSTRLEN];
	char ipstr[INET6_ADDRSTRLEN];
	void *traverser;

	
	int iNodecount=0;
	/*Side note to self a pointer to struct sockaddr_in can be cast to a pointer
	 of sockaddr and vice versa same goes for its ipv6 counterpart*/
	for(ptr=res;ptr!=NULL;ptr=ptr->ai_next)
	{
		//void *traverser;//pointer variable to store value of arg 2 of our
		// inet_ntop function
		int iBufferLen=-1;

		if(ptr->ai_family == AF_INET)
		{	
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)ptr->ai_addr;
			iBufferLen=INET_ADDRSTRLEN;
			traverser=&(ipv4->sin_addr);
			
		}
		else if(ptr->ai_family == AF_INET6)
		{
			struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)ptr->ai_addr;
			iBufferLen=INET6_ADDRSTRLEN;
			traverser=&(ipv6->sin6_addr);
			
		}

		//char *buf=(char *)malloc(iBufferLen*sizeof(char));

		//inet_ntop(ptr->ai_family,traverser,buf,iBufferLen);
		inet_ntop(ptr->ai_family,traverser,ipstr,sizeof(ipstr));

		printf("IP address is: %s\n ",ipstr);
		printf("\t address length is: %lu\n",ptr->ai_addrlen);
		printf("\t Canonncial hostname is: %s \n",ptr->ai_canonname);
		//printf("IP address is: %s\n ",ipstr);
		//printf("Value of bufferlength is: %d\n",iBufferLen);
		iNodecount++;
		//free(buf);
		//buf=NULL;
	}

	printf("Amount of nodes is: %d\n", iNodecount);
	freeaddrinfo(res);
	
	return 0;
}
