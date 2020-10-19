/*
	This program rename all names of regular files with sequential number. (1.txt, 2.txt, 3.txt, 4.txt etc).
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	DIR *dirptr = NULL;
	struct dirent *dptr = NULL;
	struct stat filestat;
	char oldpath[300] = {"\0"};
	char newpath[300] = {"\0"};
	
	int i = 1;
	int iRet = 0;
	
	dirptr = opendir(argv[0]);
	if(dirptr==NULL)
	{
		printf("Error : Unable to open directory.....\n");
		return -1;
	}
	else
	{
		while((dptr = readdir(dirptr))!=NULL)
		{
			sprintf(oldpath,"%s/%s",argv[0],dptr->d_name);
			iRet = stat(oldpath,&filestat);
			if(iRet==-1)
			{
				printf("Error : Something went wrong...\n");
				break;
			}
			else
			{
				if(S_ISREG(filestat.st_mode))
				{
					sprintf(newpath,"%s/%d.txt",argv[0],i++);
					rename(oldpath,newpath);
				}
			}
		}
	}
}
