/*
	Problem Statement : 	Write a program which create three level process hierarchy where process 1 creates
				process 2 and it internally creates process 3.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int iRet1 = 0;
	int iRet2 = 0;
	int iRet3 = 0;
	pid_t pid = 0;
	int iCnt = 0;
	int status;
	
	if((iRet1 = fork())==0)
	{	
		printf("Process-1 is created.......\n");
		if((iRet2=fork())==0)
		{
			printf("Process-2 is created.......\n");	
			if((iRet3=fork())==0)
			{
				printf("Process-3 is created.......\n");
				execl("./Process3","",NULL);
				printf("--------------------------------\n");
			}
			else
			{
				pid = wait(&status);
				if(pid==-1)
				{
					printf("Wait...P3");
				}
				else
				{
					printf("%d is terminated....\n",pid);									
				}
				
				execl("./Process2","",NULL);
				printf("--------------------------------\n");
			}
		}
		else
		{
			pid = wait(&status);
			if(pid==-1)
			{
				printf("Wait...P3");
			}
			else
			{
				printf("%d is terminated....\n",pid);									
			}
			
			execl("./Process1","",NULL);
			printf("--------------------------------\n");
		}
	}
	else
	{
		pid = wait(&status);
		if(pid==-1)
		{
			printf("Wait...P1");
		}
		else
		{
			printf("%d is terminated....\n",pid);									
		}
	}
	exit(0);
}
