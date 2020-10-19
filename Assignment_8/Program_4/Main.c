/*
	Problem Statement :		Write a program which is used to print priority of current process.
*/

#include<stdio.h>
#include<sys/resource.h>
#include<sys/types.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int iRet = 0;
	int iPriority = 0;
	
	if((iRet = fork())==0)
	{
		execl("./Priority","",NULL);
	}
	else
	{
		wait(&iRet);
		iPriority = getpriority(PRIO_PROCESS,getpid());
		printf("Priority of parent current process is : %d\n",iPriority);
	}
	
	return 0;
}

