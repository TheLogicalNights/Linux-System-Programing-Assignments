/*
	Problem Statement : 	Write a program which accept file name which contains data of all file. We have to print all
				file names whose size is greater that 10 bytes.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	int iRet = 0;
	int i = 0;
	int j = 0;
	int iSize = 0;
	int seek = 0;
	
	char first[1000] = {'\0'};
	char ch = '\0';
	char file[60] = {'\0'};
	char size[20] = {'\0'};
	if(argc!=2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for the help\n");
		return -1;
	}
	
	iFd = open(argv[1],O_RDONLY);
	if(iFd==-1)
	{
		printf("Error : Unable to open %s\n",argv[1]);
	}
	else
	{
		while((iRet = read(iFd,&ch,1))>0)
		{
			first[i] = ch;
			if(first[i]=='\n')
			{
				sscanf(first,"%s %s",file,size);
				iSize = atoi(size);
				seek = seek+iSize;
				if(iSize>10)
				{
					lseek(iFd,seek,SEEK_SET);
					printf("%d  %s  %d\n",++j,file,iSize);
					i = 0;
					ch = '\0';
					iRet = 0;
					memset(first,'\0',sizeof(first));
					memset(file,'\0',sizeof(file));
					memset(size,'\0',sizeof(size));
				}
				i = 0;
				ch = '\0';
				iRet = 0;
				memset(first,'\0',sizeof(first));
				memset(file,'\0',sizeof(file));
				memset(size,'\0',sizeof(size));
			}
			else
			{
				i++;
			}	
		}
	}
	close(iFd);
	return 0;
}
