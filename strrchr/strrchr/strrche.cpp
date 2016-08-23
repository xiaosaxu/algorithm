#include <stdio.h>
#include <conio.h>
#include <string.h>
#pragma warning (disable:4996)
int main(void)
{
	char string[20];
	char *ptr;
	char c='r';
	strcpy(string,"There are two rings");
	ptr=strrchr(string,c);
	//ptr=strchr(string,c);
	if (ptr!=NULL)
	{
		printf("The character %c is at position:%s\n",c,ptr);
	}
	else
	{
		printf("The character was not found\n");
	}
	getch();
	return 0;
}