#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	printf("Process-3 is running....\n");
	printf("PID of process-3 is : %d\n",getpid());
	
	return 0;
}
