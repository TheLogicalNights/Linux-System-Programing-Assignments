/*
    Problem Statement : Write a program which accept file name from user and read whole file.
*/

#include<stdio.h>                                       //for IO operations
#include<fcntl.h>                                       //for open and O_RDONLY macro
#include<unistd.h>                                      //close fuction
#include<string.h>                                      //for strcmp                           

int main(
        int argc,                                       //count of commandline arguments
        char *argv[]                                    //array of commandline arguments    
        )
{
    int iFd = 0;
    char cBuffer[1025];

    if(argc!=2)                                         //if running executable only i.e ./ReadAll
    {
        printf("Error : Invalid number of arguments,\nUse %s <-h> or %s <-h> for help\n",argv[0],argv[0]);
        return -1;
    }
    if((strcmp(argv[1],"-h")==0) || (strcmp(argv[1],"-H")==0))        //for ./ReadAll -h or ./ReadAll -H
    {
        printf("Use : %s <filename>\n",argv[0]);
        return 0;
    }
    else                                                //if ./Read filename
    {
        iFd = open(argv[1],O_RDONLY);                   //to open file in read mode only

        if(iFd==-1)                                     //if file dosn't open
        {
            printf("Error : Unable to open %s\n",argv[1]);
            return -1;
        }
        else                                            //if file open successfully
        {
            while(read(iFd,cBuffer,1024) != 0)          //to read 1024 byte data from the file
            {
                cBuffer[1025] = '\0';                   //initializing last byte with \0
                printf("%s",cBuffer);
            }
            printf("\n");
            close(iFd);                                 //closing file i.e releasing the resources
        }
    }
    return 0;
}