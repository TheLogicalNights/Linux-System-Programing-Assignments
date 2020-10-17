/*
	Problem Statement : 	Write a program which creates one child process, and parent process waits till its
			    	child process terminates.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int iRet = 0;
	pid_t pid;
	int status;
	if((iRet = fork())==0)
	{
		printf("Child process is created by parent process.......\n");
		execl("./Process1","",NULL);
	}
	else
	{
		pid = wait(NULL);
		if(pid==-1)
			printf("Waiting...");
		
		printf("------------Child process %d is terminated--------------\n",pid);
		printf("Parent process is running.......\n");
		printf("PID of parent process is : %d\n",getpid());
		printf("------------Parent process %d is terminated--------------\n",getpid());
	}
	
	exit(0);
}
