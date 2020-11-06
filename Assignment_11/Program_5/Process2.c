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
    long int MsgToRcv = 0;
    int iRet = 0;

	key = ftok("/usr/src",0);

	msgid = msgget(key,0666 | IPC_CREAT);
	
	if(msgid==-1)
	{
		printf("Error : Unable to create messege queue..\n");
		return -1;
	}
	else
	{
        while(1)
        {
		    msgrcv(msgid,(void*)&mymsg,BUFSIZ,MsgToRcv,0);
            printf("Msg form process-1 : %s\n",mymsg.msg);
            if(strcasecmp(mymsg.msg,"end")==0)
            {
                break;
            }
        }
	}
	return 0;	
}


