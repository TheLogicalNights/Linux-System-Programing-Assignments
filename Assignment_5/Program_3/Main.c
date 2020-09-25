/*
	Problem Statement : Write a program which accept directory name from user and write information of all
			    regular file in and then read the contents from that file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#define BUFF_SIZE 1024

int main(int argc,char *argv[])
{
	int iFd = 0;
	int iLen = 0;
	int iWrite = 0;
	int iRead = 0;
	DIR *pDir = NULL;
	struct dirent *dirptr = NULL;
	struct stat fileptr;
	char path[300] = {'\0'};
	char data[BUFF_SIZE] = {'\0'};
	char newline[1] = {'\n'};
	char cRead[BUFF_SIZE] = {'\0'};
	
	if(argc!=3)
	{
		printf("Error : Invalid Number of arguments\nUse <make help> for help\n");
		return -1;
	}
	iFd = open(argv[2],O_WRONLY|O_APPEND|O_TRUNC);
	if(iFd==-1)
	{
		printf("Error : Unable to open file %s\n",argv[2]);
		return -1;
	}
	
	pDir = opendir(argv[1]);
	if(pDir==NULL)
	{
		printf("Error : Unable to open directory %s\n",argv[1]);
		return -1;
	}
	else
	{
		while((dirptr = readdir(pDir)) != NULL)
		{
			sprintf(path,"%s/%s",argv[1],dirptr->d_name);
			stat(path,&fileptr);
			if(S_ISREG(fileptr.st_mode))
			{
				sprintf(data,"File Name : %s",dirptr->d_name);
				iLen = strlen(data);
				iWrite = write(iFd,data,iLen);
				iWrite = write(iFd,newline,1);
				memset(data,'\0',sizeof(data));
				
				sprintf(data,"iNode Numbner : %ld",fileptr.st_ino);
				iLen = strlen(data);
				iWrite = write(iFd,data,iLen);
				iWrite = write(iFd,newline,1);
				memset(data,'\0',sizeof(data));
				
				sprintf(data,"File type : Regular File");
				iLen = strlen(data);
				iWrite = write(iFd,data,iLen);
				iWrite = write(iFd,newline,1);
				memset(data,'\0',sizeof(data));
				
				sprintf(data,"File Size : %ld",(long)fileptr.st_size);
				iLen = strlen(data);
				iWrite = write(iFd,data,iLen);
				iWrite = write(iFd,newline,1);
				memset(data,'\0',sizeof(data));
				
				sprintf(data,"Block Size : %ld",(long)fileptr.st_blksize);
				iLen = strlen(data);
				iWrite = write(iFd,data,iLen);
				iWrite = write(iFd,newline,1);
				memset(data,'\0',sizeof(data));
				
				sprintf(data,"Allocated Blocks : %ld",(long)fileptr.st_blocks);
				iLen = strlen(data);
				iWrite = write(iFd,data,iLen);
				iWrite = write(iFd,newline,1);
				memset(data,'\0',sizeof(data));
				
				sprintf(data,"Hard Links : %ld",(long)fileptr.st_nlink);
				iLen = strlen(data);
				iWrite = write(iFd,data,iLen);
				iWrite = write(iFd,newline,1);
				memset(data,'\0',sizeof(data));
				
				iWrite = write(iFd,newline,1);	
			}			
		}
		close(iFd);
		iFd = open(argv[2],O_RDONLY);		
		while((iRead = read(iFd,cRead,BUFF_SIZE)) != 0)
		{
			cRead[iRead] = '\0';
			printf("%s",cRead);
		}		
		
	}
	close(iFd);
	return 0;
}
