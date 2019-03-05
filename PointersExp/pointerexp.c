#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

char *atest(void *src)
{
	//char *teststring="hello world";
	//char testbuf[11]; // 11 bytes 10 for the digits, 1 for NULL terminiator
	uint32_t *ui32PlaceHolder=(uint32_t *)src;
	uint32_t ui32Num=*ui32PlaceHolder;
	char *buf=NULL;
	buf=
	
	return NULL;
}

int main(int argc, char *argv[])
{
	int i=90;
	int *iAddr=&i;

	//unsigned long long a=0xFFFFFFFFFFFFFFFF;

	//uint32_t a32=a;

	char *cPrintString="Address of variable i is: ";

	fputs(cPrintString,stdout);
	printf("%p\n",(void *)iAddr);

	char *cPrintStringZ="Address of its pointer, i.e iAddr ";
	fputs(cPrintStringZ,stdout);
	printf("%p\n",(void *)&iAddr);

	printf("%lu\n",sizeof(size_t));

	printf("size of uint32_t is : %zu\n",sizeof(uint32_t));

	printf("size of char is: %lu\n",sizeof(char));
}

