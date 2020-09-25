/*
	Problem Statement : Write a program which accept file name and position from user and read 20 bytes from
			    that position.
*/

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	int iSize = 0;
	int iRead = 0;
	char cBuffer[21] = {'\0'};
	
	if(argc!=3)
	{
		printf("Error : Insufficient number of arguments\nUse <make help> for help\n");
		return -1;
	}
	
	iFd  = open(argv[1],O_RDONLY);
	if(iFd==-1)
	{
		printf("Error : Unable to open file\n");
		return -1;	
	}
	else
	{
		iSize = lseek(iFd,0,SEEK_END);
		if(atoi(argv[2]) > iSize)
		{
			printf("Error : Position is greater than the file size\n");
			close(iFd);
			return -1;
		}
		else
		{
			lseek(iFd,atoi(argv[2]),SEEK_SET);
			while((iRead=read(iFd,cBuffer,20) != 0))
			{
				cBuffer[21] = '\0';
				break;
			}
			printf("%s\n",cBuffer);
		}	
	}	
	close(iFd);
	return 0;
}

