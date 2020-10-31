/*
	Problem Statement : 	Write a program which creates single thread and it accept one value from
							user and it return some value to the caller thread.
*/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * Thread(void *iNo)
{
	iNo = (int)iNo * (int)iNo;
	pthread_exit(iNo);
}

int main()
{
	int iNo = 0;
	int iSquare;
	pthread_t thread;
	
	printf("Enter a number\n");
	scanf("%d",&iNo);
	
	pthread_create(&thread,NULL,Thread,(void *)iNo);
	
	pthread_join(thread,&iSquare);
	
	printf("The square of %d is : %d\n",iNo,iSquare);
	
	return 0;
}
