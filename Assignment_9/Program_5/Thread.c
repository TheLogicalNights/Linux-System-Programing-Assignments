/*
	Problem Statement : 	Write a program which is used to get thread id inside its thread function.
*/

#include<stdio.h>
#include<pthread.h>

void * Thread(void *args)
{
	printf("Callback function running.......\n");
	printf("Thread Id is : %ld\n",pthread_self());
	
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread;
	
	pthread_create(&thread,NULL,Thread,NULL);
	
	pthread_join(thread,NULL);
	
	return 0;
}
