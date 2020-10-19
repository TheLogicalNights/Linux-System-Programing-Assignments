/*
	Problem Statement :		Write a program which creates two processess.
							Process 1 count number of capital characters from demo.txt file. And process 2 count
							number of capital characters from hello.txt file. Both the processess writes its count in
							count.txt file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int iRet = 0;
	
	if((iRet = fork())==0)
	{
		printf("Process-1 is rinning....\n");
		execl("./Count",argv[1],NULL);
	}
	else
	{
		if((iRet = fork())==0)
		{
			printf("Process-2 is rinning....\n");
			execl("./Count",argv[2],NULL);
		}
		else
		{
			wait(&iRet);
			printf("Capital count is sussessfully calculated.....\n");
		}
	}
	
	return 0;
}
