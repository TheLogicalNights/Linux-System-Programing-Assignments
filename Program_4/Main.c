/*
	Problem Statement : Write a program which accept two file names from user and copy the contents of an
			   existing file into newly created file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define BUFF_SIZE 1024

int main(int argc,char *argv[])
{
	int iFd1 = 0;
	int iFd2 = 0;
	int iFd3 = 0;
	int iRet1 = 0;
	int iRet2 = 0;
	int iLen = 0;
	char cBuffer[BUFF_SIZE] = {'\0'};
	
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
	else
	{
		iFd1 = open(argv[1],O_RDONLY);
		if(iFd1==-1)
		{
			printf("Error : Unable to open file %s\n",argv[1]);
		}
		else
		{
			iRet1 = read(iFd1,cBuffer,BUFF_SIZE);
			if(iRet1==-1)
			{
				printf("Error : Unable to read file");
				return -1;
			}
		}
		iFd2 = creat(argv[2],0777);
		if(iFd2==-1)
		{
			printf("Error : Unable to create file %s\n",argv[2]);
			return -1;
		}
		else
		{
			iFd2 = open(argv[2],O_WRONLY);
			if(iFd2==-1)
			{
				printf("Error : Unable to open file %s\n",argv[2]);
				return -1;
			}
			else
			{
				iLen = strlen(cBuffer);
				iRet2 = write(iFd2,cBuffer,iLen);
				if(iRet2==-1)
				{
					printf("Error : Unable to write file\n");
					return -1;
				}
				printf("%s copied into %s successfully......\n",argv[1],argv[2]);
				close(iFd1);
				close(iFd2);
			}		
		}
	}
		return 0;
}
