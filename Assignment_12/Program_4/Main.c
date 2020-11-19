/*
	Problem Statement : Write a program which accept user defined signal from terminal.
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
	switch(iNo)
	{
		case SIGUSR1 :  printf("User defined 1 signal received..\n");
						break;
		
		case SIGUSR2 :  printf("User defined 2 signal received..\n");
						break;				
	}
}
int main()
{
	int i = 0;
	printf("Process runing with PID - %d\n",getpid());
	
	for(i=0;i<=64;i++)
	{
		signal(i,SignalHandler);	
	}
	
	for(;;);
	
	return 0;
}
