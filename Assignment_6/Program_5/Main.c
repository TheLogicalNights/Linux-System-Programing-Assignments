/*
	Problem Statement : 	Write a program which accept directory name from user and create hole in file if size is
				less than 1kb & if it is greater than 1kb then truncate the remaining data.
*/

#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
	DIR *pDir = 0;
	struct dirent *dirptr = NULL;
	struct stat fileptr;

	int iFd = 0;
	int seek = 0;
	int size = 1024;
	int extrasize = 0;
	int iRet = 0;
	
	char path[500] = {'\0'};
	char *data;
	char data1[1024] = {'\0'};
	if(argc!=2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	pDir = opendir(argv[1]);
	if(pDir==NULL)
	{
		printf("Error : Unable to open directory\n");
		return -1;
	}
	else
	{
		while((dirptr = readdir(pDir))!=NULL)
		{
			sprintf(path,"%s/%s",argv[1],dirptr->d_name);
			stat(path,&fileptr);
			if(S_ISREG(fileptr.st_mode))
			{
				if((fileptr.st_size) > 1024)
				{
					printf("1 %s\n",dirptr->d_name);
					printf("%s\n",path);
					iFd = open(path,O_RDONLY);
					if(iFd==-1)
					{
						printf("Error : Unable to open %s in read mode\n",path);
						closedir(pDir);
						return -1;
					}
					else
					{
						data = (char *)malloc(sizeof(char) * fileptr.st_size);
						memset(data,'\0',size);
						while((iRet = read(iFd,data,fileptr.st_size)) != 0)
						{
							data[iRet] = '\0';
						}
					}
					close(iFd);
					iFd = open(path,O_WRONLY|O_TRUNC);
					if(iFd==-1)
					{
						printf("Error : Unable to open %s in write mode\n",path);
						closedir(pDir);
					}
					else
					{
						write(iFd,data,size);					
					}
					close(iFd);
				}
				else
				{
					printf("2 %s\n",dirptr->d_name);
					printf("%s\n",path);
					iFd = open(path,O_RDONLY|O_WRONLY);
					if(iFd==-1)
					{
						printf("Error : Unable to open %s in read mode\n",path);
						closedir(pDir);
						return -1;
					}
					else
					{
						lseek(iFd,10,SEEK_SET);
						write(iFd,"\0",2);
						lseek(iFd,100,SEEK_SET);
						write(iFd,"\0",2);
						lseek(iFd,106,SEEK_SET);
						write(iFd,"\0",2);
						lseek(iFd,500,SEEK_SET);
						write(iFd,"\0",2);
						lseek(iFd,0,SEEK_SET);
						write(iFd,"\0",2);
					}
					close(iFd);
					memset(data1,'\0',size);						
				}
			}
		}
	}
	close(iFd);
	free(data);
	closedir(pDir);
	return 0;
}
