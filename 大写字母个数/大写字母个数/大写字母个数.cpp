// 大写字母个数.cpp : 定义控制台应用程序的入口点。
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{

	char  shuru[100];
	
	int i=0,sum=0;

	gets(shuru);
	if(strlen(shuru)==0)
	{
		printf("0\n");
		return 0;
	}

	for(i=0;i<strlen(shuru);i++)
		if(shuru[i]>='A'&&shuru[i]<='Z')
			sum++;

	printf("%d\n",sum);

//system("pause");

	return 0;
}

