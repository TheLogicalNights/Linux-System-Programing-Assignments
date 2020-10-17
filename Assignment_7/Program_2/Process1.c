#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	printf("Process-1 is running....\n");
	printf("PID of process-1 is : %d\n",getpid());
	
	return 0;
}
