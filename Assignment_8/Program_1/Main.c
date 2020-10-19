/*
	Problem Statement :		Write a program which creates new process which is responsible to write all file
							names which are present on desktop in demo.txt file which should be created newly.
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int iRet = 0;
	
	if((iRet=fork())==0)
	{
		printf("File names are copying...\n");
		execl("./file","",NULL);
	}
	else
	{
		wait(&iRet);
		printf("File names on the desktop gets successfully copied in file Demo.txt.....\n");
	}
}
