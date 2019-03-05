#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 4
using namespace std;

int tNum[NUM_THREADS];
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

// To do: ensure the scanfs of two threads do not 
// interleave with one another

void *helper(void *pArg)
{
	//sleep(1);
	int *iPlaceholder=(int *) pArg;
	int iNum=*iPlaceholder;
	int iDummy=0;
	//pthread_mutex_lock(&m);
	for(int i=0;i<4;i++)
	{
		
	}
	//usleep(1000 * (random() % NUM_THREADS+NUM_THREADS));
	//scanf("%d\n",&iDummy);
	//pthread_mutex_unlock(&m);
	//printf("Value of iDummy is: %d\n",iDummy);
	//printf("Value of iNum is: %d\n",iNum);
	//fflush(stdout);
	return 0;
}

int main(int argc, char *argv[])
{
	int i=0;
	//int tNum[NUM_THREADS];
	pthread_t tid[NUM_THREADS];
	pthread_t ptExp;
	pthread_t tDiag[NUM_THREADS];

	for(int j=0;j<4;j++)
	{
		tNum[j]=0;
	}
	//
	for(i=0;i<NUM_THREADS;i++)
	//{
		//tNum[i]=i;
		//tDiag[i]=i;
		//printf("Loop counter is: %d\n",(pthread_t)tDiag[i]);
		//scanf("%d",&tNum[i]);
		//pthread_create(&tid[i], NULL, helper, &tDiag[i]);
		//printf("Loop counter is: %d\n",(pthread_t)tDiag[i]);
	//}

	//for(i=0;i<NUM_THREADS;i++)
	//{
		//pthread_join(tid[i],NULL);
	//}

	for(int j=0;j<NUM_THREADS;j++)
	{
		cout << tNum[j] << endl;
	}
	//int i=10;
	//pthread_create(&tid,NULL,helper,&i);
	return 0;

}
