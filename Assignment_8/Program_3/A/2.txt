/*
	Problem Statement : 	Write a program which creates one process which accept one directory name. That
							process will rename all names of regular files with sequential number. (1.txt, 2.txt,
							3.txt, 4.txt etc).
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
	int iRet = 0;
	if(argc!=2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help..\n");
		return -1;
	}
	if((iRet = fork())==0)
	{
		execl("./Rename",argv[1],NULL);
	}
	else
	{
		wait(&iRet);
		printf("Renaming process is completed successfully...\n");
	}
}
