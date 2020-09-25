/*
	Problem Statement : Write a program which accept directory name from user and copy first 10 bytes from all
			    regular files into newly created file named as demo.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,char *argv[])
{
	DIR *pDir;
	struct dirent *dirptr;
	struct stat fileptr;
	
	int iRet = 0;
	int iFd = 0;
	int iFdW = 0; 
	int iRead = 0;
	int iWrite = 0;

	char cPath[300];
	char cBuffer[11] = {'\0'};
	
	if(argc!=2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	
	creat("Demo",0777);
	iFdW = open("Demo",O_WRONLY | O_APPEND);
	if(iFdW==-1)
	{
		printf("Error : Unable to open file in write mode\n");
	}	
		
	pDir = opendir(argv[1]);
	if(pDir==NULL)
	{
		printf("Error : Unable to open directory\n");
		return -1;
	}
	else
	{
		while((dirptr = readdir(pDir)) != NULL)
		{
			memset(cPath,'\0',sizeof(cPath));
			memset(cBuffer,'\0',sizeof(cBuffer));
			sprintf(cPath,"%s/%s",argv[1],dirptr->d_name);
			iFd = open(cPath,O_RDONLY);
			iRet = fstat(iFd,&fileptr);
			if(S_ISREG(fileptr.st_mode))
			{
				while((iRead = read(iFd,cBuffer,10)) != 0)
				{
					cBuffer[11] = '\0';
					iWrite = write(iFdW,cBuffer,10);
					break;					
				}
			}
			else
			{
				close(iFd);
			}			
		}
	}
	closedir(pDir);
	return 0;
}
