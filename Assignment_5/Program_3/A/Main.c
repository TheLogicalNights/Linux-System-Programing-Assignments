/*
	Problem Statement : Write a program which accept file name from user which contains information of employee, 
			    we have to read all contents of that file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define BUFF_SIZE 80

int main(int argc,char *argv[])
{
	int iFd = 0;
	int iRet = 0;
	char data[BUFF_SIZE] = {'\0'};
	
	if(argc!=2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}	
	
	iFd = open(argv[1],O_RDONLY);
	if(iFd==-1)
	{
		printf("Error : Unable to open file\n");
		return -1;
	}
	else
	{
		while((iRet = read(iFd,data,BUFF_SIZE)) != 0)
		{
			data[iRet] = '\0';
			printf("%s",data);
			memset(data,'\0',sizeof(data));
		}
	}
	close(iFd);
	return 0;
}
