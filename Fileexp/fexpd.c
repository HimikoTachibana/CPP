#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int iDirFd=-1;
	iDirFd=open(argv[1],O_RDONLY);
	if(iDirFd == -1)
	{
		printf("Error opening file: ");
	}
	ssi
	return 0;
}
