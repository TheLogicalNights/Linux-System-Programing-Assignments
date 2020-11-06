#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>

#define SHMSIZE 1024
int main()
{
	key_t key;
	char *shm = NULL,*s = NULL;
	int shmid;
	
	key = ftok("/usr/src",0);
	
	shmid = shmget(key,SHMSIZE,0666);
	
	shm = shmat(shmid,NULL,0);
	
	s = shm;
	printf("Message from Process-1 : ");
	while(*s != NULL)
	{
		printf("%c",*s);
		s++;
	}
	printf("\n");
	*shm = '*';
	
	exit(0);	
}
