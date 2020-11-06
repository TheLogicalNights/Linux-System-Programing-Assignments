#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>
#define SHMSIZE 1024
int main()
{
	char P1[1024] = {'\0'};
	key_t key;
	char *shm = NULL,*s = NULL;
	int shmid;
	int i = 0;
	
	key = ftok("/usr/src",0);
	
	shmid = shmget(key,SHMSIZE,IPC_CREAT | 0666);
	
	shm = shmat(shmid,NULL,0);
	
	printf("Enter message for Process-2...\n");
	scanf(" %[^'\n']s",P1);
		
	s = shm;
	
	for(i=0;P1[i] != '\0';i++)	
	{
		*s = P1[i];
		s++;
	}
	*s = NULL;
	
	while(*shm != '*')
	{
		sleep(1);
	}	
	
	exit(0);	
}
