#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc,char *argv[])
{
	struct stat stat;
	int iRet = 0;
	int iFd = 0;
	int iType = 0;
	if(argc>2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	else if(argc==1)
	{
		printf("Error : please enter filename\nUse <make help> for help\n");
		return -1;
	}
	else
	{
		iFd = open(argv[1],O_RDWR);
		if(iFd==-1)
		{
			printf("Error : Unable to open file\n");
			return -1;
		}
		else
		{
			iRet = fstat(iFd,&stat);
			if(iRet==-1)
			{
				printf("Error : Unable to fetch details\n");
				return -1;
			}
			else
			{
				printf("File name : %s\t",argv[1]);
				printf("Device Id : %ld\n",(long)stat.st_dev);
				printf("I-node number : %ld\t\t",stat.st_ino);
				iType = stat.st_mode & S_IFMT;
				switch(iType)
				{
					case S_IFREG : printf("File type : Regular file\n"); break;
					case S_IFDIR : printf("File type : Directory file\n"); break;
					case S_IFCHR : printf("File type : Character device\n"); break;
					case S_IFBLK : printf("File type : Block Device\n"); break;
					case S_IFIFO : printf("File typ : FIFO or pipe\n"); break;
					case S_IFSOCK : printf("File type : Socket\n"); break;
					case S_IFLNK : printf("File type : Symbolic link\n"); break;
					default : printf("Unknown type of file\n"); 
				}
				printf("Number of hard links : %ld\n",(long)stat.st_nlink);				
				printf("Permissions : User-%s%s%s Group- %s%s%s Others- %s%s%s\n",
				(stat.st_mode & S_IRUSR) ? "r" : "-",
				(stat.st_mode & S_IWUSR) ? "w" : "-",
				(stat.st_mode & S_IXUSR) ? "x" : "-",
				(stat.st_mode & S_IRGRP) ? "r" : "-",
				(stat.st_mode & S_IWGRP) ? "w" : "-",
				(stat.st_mode & S_IXGRP) ? "x" : "-",
				(stat.st_mode & S_IROTH) ? "r" : "-",
				(stat.st_mode & S_IWOTH) ? "w" : "-",
				(stat.st_mode & S_IXOTH) ? "x" : "-");
					
				printf("User Id : %ld\n",(long)stat.st_uid);
				printf("Group Id : %ld\n",(long)stat.st_gid);
				printf("Total size of file : %ld\n",(long)stat.st_size);
				printf("Block size : %ld\t\t",(long)stat.st_blksize);
				printf("No of allocated blocks : %ld\n",stat.st_blocks);
				printf("Last file accessed : %s\n",ctime(&stat.st_atime));
				printf("Last file modified : %s\n",ctime(&stat.st_mtime));
				printf("Last status changed : %s\n",ctime(&stat.st_ctime));
				close(iFd);
				return 0;
			}
		}
	}
}
