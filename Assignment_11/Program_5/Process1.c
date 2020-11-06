/*
	Problem Statement : Write a program which performs interprocess communication using the concept of
						message queue.
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>

struct msgq
{
	long int msg_type;
	char msg[BUFSIZ];
};

int main()
{
	int msgid = 0;
	key_t key;
	struct msgq mymsg;
	char Messege[BUFSIZ];

	key = ftok("/usr/src",0);

	msgid = msgget(key,0666|IPC_CREAT);
	printf("%d\n",msgid);
	if(msgid==-1)
	{
		printf("Error : Unable to create messege queue..\n");
		return -1;
	}
	else
	{
		while(1)
		{
			printf("Enter messege..\n");
			scanf(" %[^'\n']s",Messege);
			mymsg.msg_type = 1;
			strcpy(mymsg.msg,Messege);
			int iRet = msgsnd(msgid,(void *)&mymsg,BUFSIZ,0);
			if(iRet==-1)
			{
					printf("Error : Unable to send messege..\n");
					break;
			}
			if(strcasecmp(Messege,"end")==0)
			{
				break;
			}
		}
	}
	return 0;	
}


