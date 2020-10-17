#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	printf("Child process is running...\n");\
	printf("PID is : %d\n",getpid());
	
	return 0;
}
