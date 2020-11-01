/*
	Problem Statement : 	Write a program which is used to predict the problem due to lack of
							synchronization.
*/
#include<stdio.h>
#include<pthread.h>

int iCount;
void * Thread(void *iNo)
{
	iCount++;
	int i = 0;
	int iSum = 5;
	printf("Thread - %d is running......\n",iCount);
	iSum = iSum + (int)iNo;
	printf("After adding %d in iSum value of iSum is : %d\n",(int)iNo,iSum);
	for(i=0;i<0Xffffffff;i++);
	printf("Thread - %d is terminated......\n",iCount);
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	int iNo1 = 2;
	int iNo2 = 4;
	
	pthread_create(&thread1,NULL,Thread,(void *)iNo1);
	pthread_create(&thread2,NULL,Thread,(void *)iNo2);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	return 0;
}
