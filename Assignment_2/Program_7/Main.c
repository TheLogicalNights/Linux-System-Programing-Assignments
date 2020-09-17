
/*
	Problem Statement : Write a program which accept file name from user and write string in that file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	int iRet = 0;
	int iLen = 0;
	char cString[1024] = {'\0'};
	
	if(argc>2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	else if(argc==1)
	{
		printf("Error : please enter filename\nUse <make help> for help\n");
		return -1;
	}
	else
	{
		iFd = open(argv[1],O_WRONLY | O_TRUNC);
		if(iFd==-1)
		{
			printf("Error : Unable to open file\n");
			return -1;
		}
		else
		{
			printf("Enter a String\n");
			scanf(" %[^'\n']s",cString);
			
			iLen = strlen(cString);
			
			iRet = write(iFd,cString,iLen);
			
			if(iRet==-1)
			{
				printf("Error : Unable to write data\n");
				return -1;
			}
			else
			{
				printf("Data write to file successfully !\n");
				close(iFd);
				return 0;
			}
		}	
	}
}
