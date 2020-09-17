
/*
	Problem Statement : Write a program which accept file name from user and read whole file.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	int iRet = 0;
	char cBuffer[1024];
	
	if(argc>2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	else if(argc==1)
	{
		printf("Error : please enter file name\nUse <make help> for help\n");
	}
	
	iFd = open(argv[1],O_RDONLY);
	
	if(iFd==-1)
	{
		printf("Error : Unable to open file\n");
		return -1;
	}
	else
	{
		iRet = read(iFd,cBuffer,sizeof(cBuffer));
	
		if(iRet==0)
		{
			printf("cannot read file is empty\n");
			return 0;
		}
		else
		{
			cBuffer[iRet] = '\0';
			printf("%s",cBuffer);
		}
	}
	close(iFd);
	return 0;
}
