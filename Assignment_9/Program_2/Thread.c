/*
	Problem Statement : 	Write a program which creates two thread , first thread print numbers
							from 1 to 500 & other thread print the numbers from 500 to 1.
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * Thread1()
{
	int i = 1;
	printf("output by thread-1................");
	for(i=1;i<=500;i++)
	{
		printf("Thread-1 : %d\n",i);
	}
}

void * Thread2()
{
	int i = 1;
	printf("output by thread-2..............");
	for(i=500;i>=1;i--)
	{
		printf("Thread-2 : %d\n",i);
	}
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	
	pthread_create(&thread1,NULL,Thread1,NULL);
	pthread_create(&thread2,NULL,Thread2,NULL);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	return 0;
}
