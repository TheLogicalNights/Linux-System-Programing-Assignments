/*
	Problem Statement : 	Write a program which creates three diffrent processess internally as process2,
				process3, process4.
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
		if((iRet=fork())==0)
		{
			printf("Process-2 is created....\n");
			execl("./Process2","",NULL);
		}
	}
	else
	{
		if((iRet=fork())==0)
		{
			printf("Process-3 is created....\n");
			execl("./Process3","",NULL);
		}
		else
		{
			if((iRet=fork())==0)
			{
				printf("Process-4 is created....\n");
				execl("./Process4","",NULL);
			}
			else
			{
				while((pid=wait(&status))>0);
			}
		}
	}
	
	exit(0);
}
