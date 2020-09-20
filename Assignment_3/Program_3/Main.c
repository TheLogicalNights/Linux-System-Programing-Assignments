/*
	Problem Statement : Write a program which accept directory name from user and print name of such a file
			   having largest size.
*/

#include<dirent.h>
#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	DIR *pDir;
	struct dirent *dirptr;
	struct stat fileptr;
	int iFd = 0;
	int iRet = 0;
	int iRet1 = 0;
	long int iMax = 0;
	char cPath[300];
	char cBuffer[80] = {'\0'};
	if(argc>2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	else if(argc==1)
	{
		printf("Error : Insufficient number of arguments\nUse <make help> for help\n");
		return -1;
	}
	else
	{
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
				sprintf(cPath,"%s/%s",argv[1],dirptr->d_name);
				
				iRet = stat(cPath,&fileptr);
				if(iRet==-1)
				{
					printf("Error : Something went wrong....\n");
					break;
				}
				else
				{
					if(S_ISREG(fileptr.st_mode))
					{
						if(fileptr.st_size > iMax)
						{
							iMax = fileptr.st_size;
							memset(cBuffer,'\0',sizeof(cBuffer));
							strcpy(cBuffer,dirptr->d_name);
						}
					}
				}
			}
			if(iRet==-1)
			{
				closedir(pDir);
				return -1;
			}	
			else
			{
				printf("Name of file having maximum size is : %s\t%ld\n",cBuffer,(long)iMax);
			}
		}
		closedir(pDir);
		return 0;
	}
} 	 	
