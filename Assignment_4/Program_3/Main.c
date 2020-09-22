/*
	Problem Statement : Write a program which accept two file names from user and check whether contents of
			    that two files are equal are not.
*/

#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	struct stat file1;
	struct stat file2;
	
	int iFd1 = 0;
	int iFd2 = 0;
	int iRet1 = 0;
	int iRet2 = 0;
	int iFlag = 0;
	int iRead1 = 0;
	int iRead2 = 0;
	
	char cBuffer1[512];
	char cBuffer2[512];
	
	if(argc!=3)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	iFd1 = open(argv[1],O_RDONLY);
	if(iFd1==-1)
	{
		printf("Error : Unable to open file %s\n",argv[1]);
		return -1;
	}
	iFd2 = open(argv[2],O_RDONLY);
	if(iFd2==-1)
	{
		printf("Error : Unable to open file %s\n",argv[2]);
		return -1;
	}
	
	iRet1 = fstat(iFd1,&file1);
	if(iRet1==-1)
	{
		printf("Error : Something went wrong\n");
		close(iFd1);
		close(iFd2);
		return -1;
	}
	iRet2 = fstat(iFd2,&file2);
	if(iRet2==-1)
	{
		printf("Error : Something went wrong\n");
		close(iFd1);
		close(iFd2);
		return -1;
	}
	
	if((file1.st_size) != (file2.st_size))
	{
		printf("Contents of %s and %s are not equal\n",argv[1],argv[2]);
		close(iFd1);
		close(iFd2);
		return 0;
	}
	else
	{
		while((iRead1 = read(iFd1,cBuffer1,sizeof(cBuffer1))!=0) && (iRead2 = read(iFd2,cBuffer2,sizeof(cBuffer2))!=0))
		{
			cBuffer1[file1.st_size] = '\0';
			cBuffer2[file2.st_size] = '\0';
			if(strcmp(cBuffer1,cBuffer2) != 0)
			{
				iFlag = 1;
				break;
			}
		}
		if(iFlag==1)
		{
			printf("Contents of %s and %s are not equal\n",argv[1],argv[2]);
			close(iFd1);
			close(iFd2);
			return 0;
		}
		else
		{
			printf("Contents of %s and %s are equal\n",argv[1],argv[2]);
			close(iFd1);
			close(iFd2);
			return 0;
		}
	}	
}
