/*
	Problem Statement : 	Write a program which is used to increase the priority by 5.
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<unistd.h>

int main()
{
	printf("Default priority of current process is : %d\n",getpriority(PRIO_PROCESS,getpid()));
	nice(5);
	printf("Priority of current process after increament by 5 is : %d\n",getpriority(PRIO_PROCESS,getpid()));
	
	return 0;
}

