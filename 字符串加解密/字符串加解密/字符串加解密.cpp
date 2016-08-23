// 字符串加解密.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Encrypt (char aucPassword[], char aucResult[]);//加密
int unEncrypt (char result[], char password[]);//解密


int main(void)
{

	char aa[2][101]={0};
	char* shuru;
	int i=0;

	for(i=0;i<2;i++)
		gets(aa[i]);

	Encrypt(aa[0],aa[1]);

	unEncrypt(aa[0],aa[1]);


	//for(i=0;i<2;i++)
	//	printf("%s\n",aa[i]);


	//system("pause");
	return 0;
}

void Encrypt (char aucPassword[], char aucResult[])//解密
{
	char* psd=aucPassword,*relt=aucResult;
	int len=0,i;

	len=strlen(psd);

	for(i=0;i<len;i++)
	{
		if(psd[i]>='a'&&psd[i]<='y')
		{
			psd[i]-=32;//转化大写
			psd[i]+=1;
		}
		else 
			if(psd[i]=='z')
				psd[i]='a';//处理小写字母
			else
				if(psd[i]>='A'&&psd[i]<='Y')//处理大写字母
				{
					psd[i]+=32;//转化小写
					psd[i]+=1;//后面字母
				}
				else
					if(psd[i]=='Z')
						psd[i]='a';
					else
						if(psd[i]>='0'&&psd[i]<='8')
							psd[i]+=1;
						else
							if(psd[i]=='9')
								psd[i]='0';
	}
	printf("%s\n",psd);

}

int unEncrypt (char result[], char password[])//解密
{
	char *psd=password;
	int len=0,i;

	len=strlen(psd);

for(i=0;i<len;i++)
	{
		if(psd[i]>='b'&&psd[i]<='z')//处理小写
		{
			psd[i]-=1;
			psd[i]-=32;//转化大写
		}
		else 
			if(psd[i]=='a')
				psd[i]='Z';//处理小写字母
			else
				if(psd[i]>='B'&&psd[i]<='Z')//处理大写字母
				{
					psd[i]+=32;//转化小写
					psd[i]-=1;//后面字母
				}
				else
					if(psd[i]=='A')
						psd[i]='z';
					else
						if(psd[i]>='1'&&psd[i]<='9')
							psd[i]-=1;
						else
							if(psd[i]=='0')
								psd[i]='9';
	}
	printf("%s\n",psd);

	return 0;
}