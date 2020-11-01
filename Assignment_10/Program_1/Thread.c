/*
	Problem Statement : 	Write a program which creates 4 number of threads and our main thread
							waits till all the thread terminates.
*/

#include<stdio.h>
#include<pthread.h>

int i = 1;
void * Thread(void *iNo)
{
	printf("Thread - %d is running...\n",i);
	printf("Thread - %d is terminated...\n",i++);
	pthread_exit(NULL);
}

int main()
{
	int i=0;
	pthread_t thread[4];
	
	for(i=0;i<4;i++)
	{
		pthread_create(&thread[i],NULL,Thread,NULL);
		pthread_join(thread[i],NULL);
	}
}
