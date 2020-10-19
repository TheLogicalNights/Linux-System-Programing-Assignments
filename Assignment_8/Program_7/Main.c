/*
	Problem Statement : 	Write a program which is used to pring home directory and login user name.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("home directory is : %s\n",getenv("HOME"));
	printf("login user name is : %s\n",getenv("LOGNAME"));
	return 0;
}
