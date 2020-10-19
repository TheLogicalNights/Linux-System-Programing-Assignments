/*
	This program prints the priority of current running process.
*/

#include<stdio.h>
#include<sys/resource.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int iPriority = 0;
	
	iPriority = getpriority(PRIO_PROCESS,getpid());
	printf("Priority of child current process is : %d\n",iPriority);
	
	return 0;
}
