/*
	write all file names which are present on desktop in demo.txt file which should be created newly
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>

int main(int argc,char *argv[])
{
	DIR *dirptr=NULL;
	struct dirent *dptr = NULL;
	
	int iFd = 0;
	int iWrite = 0;
	
	char home[5] = "home";
	char user[8] = "swapnil";
	char desktop[8] = "Desktop";
	char Path[80] = {"\0"};
	char file[300] = {"\0"};
	
	sprintf(Path,"/%s/%s/%s/",home,user,desktop);	
	dirptr = opendir(Path);
	
	if(dirptr==NULL)
	{
		printf("Error : Unable to open directory\n");
		return -1;
	}
	else
	{
			creat("Demo.txt",0777);
			iFd = open("Demo.txt",O_WRONLY);
			if(iFd==-1)
			{
				printf("Error : Unable to open file in write mode\n");
				return -1;
			}
			else
			{
				while((dptr = readdir(dirptr))!=NULL)
				{
					sprintf(file,"%s",dptr->d_name);
					iWrite = write(iFd,file,strlen(file));
					write(iFd,"\n",1);
					memset(file,'\0',sizeof(file));
				}	
			}
	}
	
	return 0;
}
