/*
	Problem Statement : Write a program which creates such a process which accept signals from the terminal.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<signal.h>

void SignalHandler(int iNo)
{
	printf("Signal received :- %d\n",iNo);
}
int main()
{
	int i = 0;
	printf("Process Id - %d\n",getpid());
	for(i=0;i<=64;i++)
	{
		signal(i,SignalHandler);
		
	}
	
	for(;;);
	
	return 0;
}
