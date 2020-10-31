/*
	Problem Statement : 	Write a program which is used to create simple thread by using pthread
							library.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * Thread()
{
	printf("Thread is created.....\n");
}

int main()
{
	pthread_t pthread;
	
	pthread_create(&pthread,NULL,Thread,NULL);
	
	pthread_join(pthread,NULL);
		
	return 0;
}
