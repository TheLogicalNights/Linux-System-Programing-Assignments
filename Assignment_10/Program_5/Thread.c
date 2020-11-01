/*
	Problem Statement :		Write a program which creates two threads by using pthread API, where
							one thread count number of capital characters from demo.txt file and other
							threads count number of small characters from same file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#define THREAD1 1
#define THREAD2 2

pthread_mutex_t lock;

void * Count(void *iNo)
{
	int iFd = 0;
	int iCapital = 0;
	int iSmall = 0;
	int iRet = 0;
	
	char ch = '\0';
	
	iFd = open("Demo.txt",O_RDONLY);
	if(iFd==-1)
	{
		printf("Error : Unable to open file...\n");
		pthread_exit(NULL);
	}
	else
	{
		pthread_mutex_lock(&lock);
		while((iRet=read(iFd,&ch,1))!=0)
		{
			if(THREAD1==(int)iNo)
			{
				if((ch>='A') && (ch<='Z'))
				{
					iCapital++;
				}
			}
			else if(THREAD2==(int)iNo)
			{
				if((ch>='a') && (ch<='z'))
				{
					iSmall++;
				}
			}
		}
		pthread_mutex_unlock(&lock);
	}
	if(THREAD1==(int)iNo)
	{
		printf("Count of capital characters is : %d\n",iCapital);
	}
	else
	{
		printf("Count of small characters is : %d\n",iSmall);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	int iNo1 = 1;
	int iNo2 = 2;
	
	pthread_create(&thread1,NULL,Count,(void *)iNo1);
	pthread_create(&thread2,NULL,Count,(void *)iNo2);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);		
}
