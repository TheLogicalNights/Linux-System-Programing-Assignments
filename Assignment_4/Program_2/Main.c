/*
	Problem Statement : Write a aprogram which accept directory name from user and create new directory of that
			    name.
*/

#include<sys/stat.h>
#include<stdio.h>

int main(int argc,char *argv[])
{
	int iRet = 0;
	if(argc!=2)
	{
		printf("Error : Invalid number of arguents\nUse <make help> for help\n");
		return -1;
	}
	
	iRet = mkdir(argv[1],0777);
	if(iRet==-1)
	{
		printf("Error : Unable to create directory\n");
		return -1;
	}
	else
	{
		printf("Directory created successfully\n");
		return 0;	
	}
}
