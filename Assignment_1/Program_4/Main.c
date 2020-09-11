/*
    Problem Statement : Write a program which accept file name from user and open that file.
*/

#include<stdio.h>                                   //for IO operations
#include<string.h>                                  //for strcmp
#include<fcntl.h>                                   //for open and O_RDONLY macro
#include<unistd.h>                                  //close fuction

int main(
    int argc,                                       //count of commandline arguments
    char *argv[]                                    //array of commandline arguments
    )
{
    int iFd = 0;

    if(argc!=2)                                     //if running executable only i.e ./Open
    {
        printf("Error : Inavalid number of arguments,\nUse %s <-h> or Use %s <-h> for help\n",argv[0],argv[0]);
        return -1;
    }
    if((strcmp(argv[1],"-h")==0) || (strcmp(argv[1],"-H")==0))   //for ./Open -h or ./Open -H
    {
        printf("Use : %s <file_name>\n",argv[0]);
        return 0;
    }

    iFd = open(argv[1],O_RDONLY);                   //to open file in read mode only 

    if(iFd==-1)                                     //if file dosn't open
    {
        printf("Error : Unable to open file %s\n",argv[1]);
        return -1;
    }
    else                                            //if file open successfully
    {
        printf("%s opened successfully with file descriptor %d\n",argv[1],iFd);
        
        close(iFd);                                 //closing file i.e releasing the resources         
        
        return 0;
    }
}