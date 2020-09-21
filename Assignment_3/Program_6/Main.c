/*
	Problem Statement : Write a program which accept two directory names from user and move all files from
			    source directory to destination directory.
*/


#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	DIR *pDir;
	struct dirent *dirptr;
	struct stat fileptr;
	int iRet = 0;
	char cPath1[300];
	char cPath2[300];
	
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
				sprintf(cPath1,"%s/%s",argv[1],dirptr->d_name);

				stat(cPath1,&fileptr);
				
				if((S_ISREG(fileptr.st_mode)))
				{
					sprintf(cPath2,"%s/%s",argv[2],dirptr->d_name);
					iRet = link(cPath1,cPath2);
					remove(cPath1);
					if(iRet==-1)
					{
						printf("Error : Unable to move files\n");
						break;
					}
					else
					{
						printf("files moved successfully\n");
					}
				}
			}
		}
	}
	closedir(pDir);
	return 0;
}
