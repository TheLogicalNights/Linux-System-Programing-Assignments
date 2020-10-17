/*
	Problem Statement : 	Write a program which creates two processess as process2 and process3 and our
				parent process waits till both the processess terminates.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
	int iRet = 0;
	int status = 0;
	int pid = 0;
	if((iRet=fork())==0)
	{
		printf("Process-2 is created.....\n");
		execl("./Process2","",NULL);
	}
	else
	{
		if((iRet=fork())==0)
		{
			printf("Process-3 is created.....\n");
			execl("./Process3","",NULL);
		}	
		else
		{
			while((pid=wait(&status))>0)
			{
				printf("Process %d is terminated....\n",pid);
			}
		}
	}
}
