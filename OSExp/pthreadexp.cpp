#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 4
using namespace std;

int tNum[NUM_THREADS];
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mZ = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mD = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mF = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mSec = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mFoo = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mFooZ=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mBar = PTHREAD_MUTEX_INITIALIZER;


pthread_cond_t cEin=PTHREAD_COND_INITIALIZER;
pthread_cond_t cZwei=PTHREAD_COND_INITIALIZER;
// To do: ensure the scanfs of two threads do not 
// interleave with one another

void *helper(void *pArg)
{
	//sleep(1);
	int *iPlaceholder=(int *) pArg;
	
	//pthread_mutex_lock(&m);
		//cout << "The value of placeholder is: " << iPlaceholder << endl;
	//pthread_mutex_unlock(&m);
	int iNum=*iPlaceholder;
	int iDummy=0;
	int iCount=0;
	int iEnters=0;
	int iSum=0;
	float iAverage=0.0;
	/*
	while(iCount<NUM_THREADS)
	{
		//sleep(4000);
		pthread_mutex_lock(&m);
			//sleep(4000);
			cout << "the value of iPlaceholder is: " << iPlaceholder << endl;
			cout << "The value of iNum is: " << iNum << endl;
			iCount++;
		pthread_mutex_unlock(&m);
		//sleep(8000);
		//fflush(stdin);
	}


	cout << "Out of while loop" << endl;
	fflush(stdout);
	*/
	
	//fflush(stdout);
	//pthread_mutex_lock(&m);
		//cout <<"Value of iNum is: "  <<iNum << endl;
	//pthread_mutex_unlock(&m);
	//pthread_mutex_lock(&m);


	
	pthread_mutex_lock(&m);

			//cout << "Before sleep(4) " << endl;
			//sleep(4);
			//cout << "After sleep (4) " << endl;
			//pthread_mutex_lock(&mD);
			pthread_mutex_lock(&mFooZ); // This mutex protects the loop counter
			for(int i=0;i<NUM_THREADS+1;i++) // The +1 part of the loop is to correct for off by one when accumulating
			// values into the array
			//pthread_mutex_unlock(&mFooZ);
			{
				//pthread_mutex_lock(&mSec);
				//cout << "Value of i is "  << i << " Before sleep(2) is called " << endl;
				sleep(4); // have threads sleep for some time to prevent thread interleaving
				//cout << "Value of i is " << i << " After sleep(2) is called " << endl;
				//pthread_mutex_lock(&mSec);


				pthread_mutex_lock(&mF); // mutex to protect the entire if check

				//pthread_mutex_lock(&mFooZ);
				if(((i-4)%4)<0)
				pthread_mutex_unlock(&mFooZ);
				{
					//pthread_cond_wait(&cEin,&mF);
					pthread_mutex_lock(&mSec);
						pthread_mutex_lock(&mBar);
							//cout <<" "<<i<< " i is divisible by 4 and less than 0" << endl;
						pthread_mutex_unlock(&mBar);
						//iEnters++;
						//cout << "The value of iEnter is: " << iEnters << endl;
						iEnters++;
						pthread_mutex_lock(&mFoo);
						if(iEnters == NUM_THREADS+1)
						{
							cout << "sum is " << iSum << endl;
							iAverage=iSum/(float)4;
							cout << "average is: " << iAverage << endl;
							//cout << "inside check " << endl;
							exit(0);
							//break;
							//return 0;
							//pthread_exit(0);

						}
						pthread_mutex_unlock(&mFoo);
					pthread_mutex_unlock(&mSec);

					/*pthread_mutex_lock(&mZ);
						cout << "Value of i is: " << i << endl;
						cin >> tNum[i];
					pthread_mutex_unlock(&mZ);
					
					pthread_mutex_lock(&mD);
						cout << "The value at i is: " << i << " " << tNum[i] << " " << endl;
					pthread_mutex_unlock(&mD);*/
				//break;
				}
				//pthread_cond_broadcast(&cEin);
				/*else
				{
					cout << "Inside else" << endl;
				}*/
				pthread_mutex_unlock(&mF);
				/*else
				{
					cout << "Inside else: " << endl;
					//exit(0);
					//pthread_mutex_lock(&mZ);
						//cout << "Value of i is: " << i << endl;
					//pthread_mutex_unlock(&mZ);
	
					
				}*/


		//usleep(40000);
			//sleep(1);
				pthread_mutex_lock(&mZ); //c ** This mutex protects the cout and cin statement
				//sleep(1);
					cout << "Value of i is: " << i << endl; //c
				//sleep(0);
					// /sleep(1);
					//scanf("%d\n",&tNum[i]);
					cin >> tNum[i];//c
					//pthread_cond_broadcast(&cEin);
					// /sleep(1);
					fflush(stdout);

				pthread_mutex_unlock(&mZ);//c
	
				pthread_mutex_lock(&mD);//c
					cout << "The value of tNum at i is: " <<" "<<i<<" "<<tNum[i] << endl;//c
					iSum+=tNum[i];
				pthread_mutex_unlock(&mD);//c 
				//pthread_cond_signal(&cEin);
			//pthread_mutex_unlock(&mZ);
		//scanf("%d\n",&iDummy);
			}
			//pthread_mutex_unlock(&mD);

	//fflush(stdout);
	pthread_mutex_unlock(&m);
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
	pthread_t tidZ;
	pthread_t tidO;
	pthread_t ptExp;
	//int i=0;
	pthread_t tDiag[NUM_THREADS];

	for(int j=0;j<4;j++)
	{
		tNum[j]=0;
	}

	int iP=100;


	for(int i=0;i<NUM_THREADS;i++)
	{
		tNum[i]=i;
		pthread_create(&tid[i],NULL, helper,&tNum[i]);
	}
	//pthread_create(&tidZ,NULL,helper,&iP);
	//
	//for(i=0;i<NUM_THREADS;i++)
	//{
		//tNum[i]=i;
		//tDiag[i]=i;
		//printf("Loop counter is: %d\n",(pthread_t)tDiag[i]);
		//scanf("%d",&tNum[i]);
		//pthread_create(&tid[i], NULL, helper, &tDiag[i]);
		//printf("Loop counter is: %d\n",(pthread_t)tDiag[i]);
	//}

	for(i=0;i<NUM_THREADS;i++)
	{
		pthread_join(tid[i],NULL);
	}

	for(int kk=0;kk<NUM_THREADS;kk++)
	{
		pthread_cancel(tid[kk]);
	}

	//for(int j=0;j<NUM_THREADS;j++)
	//{
		//cout << tNum[j] << endl;
	//}
	//int i=10;
	//pthread_create(&tid,NULL,helper,&i);
	return 0;

}
