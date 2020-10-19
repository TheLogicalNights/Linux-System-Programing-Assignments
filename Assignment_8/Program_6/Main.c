/*
	Problem Statement :		Write a program which is used to display Environment of our running process.
*/

#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main()
{
	char **envi = environ;
	for(;*envi!=NULL;envi++)
	{
		printf("%s\n",*envi);
		printf("-----------------------------------------------------\n");
	}
	return 0;
}
