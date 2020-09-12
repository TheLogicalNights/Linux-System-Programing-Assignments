/*
    Problem Statement : Write a program which accept filename and string from user and write that string into
                        file.
*/

#include<stdio.h>                                   //for IO operations
#include<fcntl.h>                                   //for open and O_RDONLY macro
#include<string.h>                                  //for strcmp and strlen
#include<unistd.h>                                  //close fuction

int main(
        int argc,                                   //count of commandline arguments                                    
        char *argv[]                                //array of commandline arguments
        )
{
    int iFd = 0;
    char cBuffer[1024];
    int iNumWrite = 0;
    int iLen = 0;

    if(argc!=2)                                     //if running executable only i.e ./Write
    {
        printf("Error : Invalid number of arguments\nUse %s <-h> or %s <-h> for help\n",argv[0],argv[0]);
        return -1;
    }
    if((strcmp(argv[1],"-h")==0) || (strcmp(argv[1],"-H")==0))      //for ./Write -h or ./Write -H
    {
        printf("Use : %s <filename>\n",argv[0]);
        return 0;
    }
    else                                            //for ./Write filename
    {
        iFd = open(argv[1],O_WRONLY);               //to open file in write mode only

        if(iFd==-1)                                 //if file dosn't open
        {
            printf("Error : Unable to open %s\n",argv[0]);
            return -1;
        }
        else                                        //if file open successfully
        {
            printf("Enter a String\n");
            scanf("%[^'\n']s",cBuffer);

            iLen = strlen(cBuffer);                //to count the size of string

            iNumWrite = write(iFd,cBuffer,iLen);   //writing the string into file refered by iFd

            if(iNumWrite==-1)                       //if unable to write
            {
                printf("Error : Unable to write\n");
                return -1;
            }
            close(iFd);                             //closing file i.e releasing the resources
        }
    }
    return 0;
}