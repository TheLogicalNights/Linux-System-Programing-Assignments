/*
	Problem Statement :		Write a program which creates single thread and we have to pass
							parameter to that thread from main thread.
*/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * Thread(void *iNo)
{
	printf("You passes \"%d\" as parameter\n",((int)iNo));
}

int main()
{
	pthread_t thread;
	int iNo = 0;
	
	printf("Enter a number\n");
	scanf("%d",&iNo);
	
	pthread_create(&thread,NULL,Thread,(void *)iNo);
	
	pthread_join(thread,NULL);
	
	return 0;
}
