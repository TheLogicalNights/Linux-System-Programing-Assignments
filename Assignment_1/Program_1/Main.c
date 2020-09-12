/*
    Problem Statement : Write a program which is used to add two numbers.

                        input : <executable_name> 2 3
                        output : 5

                        input : <executable_name> 10 15
                        output : 25

                        input : <executable_name> 2
                        output : Error : Invalid number of arguments ,
                                 for help use <executable_name> <-h> or <executable_name> <-H>

                        input : <executable_name> a b (or other than number)
                        output : Error : Invalid number of arguments ,
                                 for help use <executable_name> <-h> or <executable_name> <-H> 

                        input : <executable_name> -h or <executable_name> -h 
                        output : Use : <executable_name> <number1> <number2> 
*/

#include<stdio.h>                                //for IO operation
#include<string.h>                               //for strcmp function
#include<stdlib.h>                               //for atoi function

int main(int argc,                               //to sore the count of comandline arguments
        char *argv[])                            //to store the command line arguments
{
    int iSum = 0;
    int iNo1 = 0;
    int iNo2 = 0;

    if(argc == 1 || argc>3)                      //if command line arguments are 1 or more than 3
    {
        printf("Error : Invalid number of arguments ,\nfor help use %s <-h> or %s <-H>\n",argv[0],argv[0]);
        return -1;
    }
    else if((strcmp(argv[1],"-H")==0) || (strcmp(argv[1],"-h")==0) && argc==2)   //if comandline arguments are 2 and -h or -H is used
    {
        printf("Use : %s <number1> <number2>\n",argv[0]);
        return 0;
    }
    if(argc==3)                                  //if command line arguments are 3
    {
        if(((*argv[1]>='1') && (*argv[1]<='9') && ((*argv[2]>='1') && (*argv[2]<='9'))))    //if commandline arguments are numbers 
        {
            iNo1 = atoi(argv[1]);
            iNo2 = atoi(argv[2]);
        }
        else                                     //if command line arguments are other than number
        {
            printf("Error : Invalid number of arguments ,\nfor help use %s <-h> or %s <-H>\n",argv[0],argv[0]);
            return -1;
        }
        iSum = iNo1 + iNo2;
        printf("Sum of %s %s is : %d\n",argv[1],argv[2],iSum);
    }
    else                                        //if commandline arguments are 2 and other than -h or -H  
    {
        printf("Error : Invalid number of arguments ,\nfor help use %s <-h> or %s <-H>\n",argv[0],argv[0]);
        return -1;
    }
}
