/*
	Problem Statement : 	Write a program which creates two thread , and by using appropriate
							synchronization technique avoid the scheduling problem.
*/
#include<stdio.h>
#include<pthread.h>

int iCount;
pthread_mutex_t lock;
void * Thread(void *iNo)
{
	int i = 0;
	int iSum = 5;
	pthread_mutex_lock(&lock);
	iCount++;
	printf("Thread - %d is running......\n",iCount);
	iSum = iSum + (int)iNo;
	printf("After adding %d in iSum value of iSum is : %d\n",(int)iNo,iSum);
	printf("Thread - %d is terminated......\n",iCount);
	for(i=0;i<0Xffffffff;i++);
	pthread_mutex_unlock(&lock);
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
	
	pthread_mutex_destroy(&lock);
	return 0;
}
