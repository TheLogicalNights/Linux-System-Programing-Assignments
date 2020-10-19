/*
	This program counts number of capital characters from a file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	int iRet = 0;
	int iCount = 0;
	
	char ch = '\0';
	char message[80] = {"\0"};
	
	iFd = open(argv[0],O_RDONLY);
	if(iFd==-1)
	{
		printf("Error : Unable to open file : %s\n",argv[0]);
		return -1;
	}
	else
	{
		while((iRet=read(iFd,&ch,1))!=0)
		{
			if((ch>='A') && (ch<='Z'))
			{
				iCount++;
			}
		}
		creat("Count.txt",0777);
		iFd = open("Count.txt",O_WRONLY|O_APPEND);
		if(iFd==-1)
		{
			printf("Error : Unable to open file : Count.txt\n");
			return -1;
		}
		else
		{
			sprintf(message,"Capital count from %s is : %d\n",argv[0],iCount);
			write(iFd,message,strlen(message));
		}
	}
	close(iFd);
	return 0;
}
