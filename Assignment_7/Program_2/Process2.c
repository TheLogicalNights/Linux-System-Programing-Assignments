#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	printf("Process-2 is running....\n");
	printf("PID of process-2 is : %d\n",getpid());
	
	return 0;
}
