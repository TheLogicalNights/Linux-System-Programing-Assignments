/*
	Problem Statement : Write a program which accept file name and number of bytes from user and read that
			    number of bytes from file.
*/


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	int iBytes = 0;
	int iRet = 0;
	char cBuffer[1024];
	
	if(argc>3)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	else if(argc==2)
	{
		printf("Error : Insufficient number of arguments\nUse <make help> for help\n");
		return -1;
	}
	else if(argc==1)
	{
		printf("Error : Insufficient number of arguments\nUse <make help> for help\n");
		return -1;
	}
	
	iBytes = atoi(argv[2]);
	
	if((iBytes>0))
	{
		iFd = open(argv[1],O_RDONLY);
		if(iFd==-1)
		{
			printf("Error : Unable to open file\n");
			return -1;
		}
		else
		{
			iRet = read(iFd,cBuffer,iBytes);
			cBuffer[iRet] = '\0';
			printf("%s\n",cBuffer);
			close(iFd);
			return 0;
		}
	}
	else
	{
		printf("Error : Cannot read 0 bytes or less bytes\n");
		return -1;
	}
}
