// �ַ����ӽ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Encrypt (char aucPassword[], char aucResult[]);//����
int unEncrypt (char result[], char password[]);//����


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

void Encrypt (char aucPassword[], char aucResult[])//����
{
	char* psd=aucPassword,*relt=aucResult;
	int len=0,i;

	len=strlen(psd);

	for(i=0;i<len;i++)
	{
		if(psd[i]>='a'&&psd[i]<='y')
		{
			psd[i]-=32;//ת����д
			psd[i]+=1;
		}
		else 
			if(psd[i]=='z')
				psd[i]='a';//����Сд��ĸ
			else
				if(psd[i]>='A'&&psd[i]<='Y')//�����д��ĸ
				{
					psd[i]+=32;//ת��Сд
					psd[i]+=1;//������ĸ
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

int unEncrypt (char result[], char password[])//����
{
	char *psd=password;
	int len=0,i;

	len=strlen(psd);

for(i=0;i<len;i++)
	{
		if(psd[i]>='b'&&psd[i]<='z')//����Сд
		{
			psd[i]-=1;
			psd[i]-=32;//ת����д
		}
		else 
			if(psd[i]=='a')
				psd[i]='Z';//����Сд��ĸ
			else
				if(psd[i]>='B'&&psd[i]<='Z')//�����д��ĸ
				{
					psd[i]+=32;//ת��Сд
					psd[i]-=1;//������ĸ
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