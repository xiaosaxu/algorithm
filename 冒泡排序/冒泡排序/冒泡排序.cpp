// ð������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char shuru[1024];
	char *zifu;
	zifu=shuru;

	char temp;
	int len=0,i,j;	

	scanf("%s",zifu);

	len=strlen(zifu);

	for(i=0;i<len;i++)
		for(j=1;j<len-i;j++)//����Ҫ��һ �������һ��Ԫ�����򲻵�
			if(shuru[j-1]>shuru[j])//����
			{
				temp=shuru[j-1];
				shuru[j-1]=shuru[j];
				shuru[j]=temp;
			}

    printf("%s\n",zifu);

	system("pause");

	return 0;
}

