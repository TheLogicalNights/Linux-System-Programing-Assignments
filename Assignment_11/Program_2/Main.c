#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int iRet = 0;
	
	if((iRet = fork())==0)
	{
		execl("./Process1","",NULL);
	}
	else
	{
		sleep(10);
		if((iRet = fork())==0)
		{
			execl("./Process2","",NULL);
		}
		
		wait(&iRet);
	}
	
	return 0;
}
