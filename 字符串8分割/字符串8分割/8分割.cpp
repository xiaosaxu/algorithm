/*��ʼʱ�䣺 2016-08-13 11:19:22
ʵ�ֹ��ܣ�
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std; 

void fenge(char * shuru)
{
	int i,j,k;
	if(strlen(shuru)==0)
		return;

	for(i=strlen(shuru)-1;i>=0; i--)
		shuru[i+1]=shuru[i];//����Ԫ���������ƶ�һλ

	for(i=1;i<(strlen(shuru)-1)/8*8+1; i++)//��һ����
	{
		printf("%c",shuru[i]);
		if(i%8==0)
			printf("\n");
	}

	for(i;i<strlen(shuru); i++)//�ڶ�����
	{
		printf("%c",shuru[i]);
	}
	if(((strlen(shuru)-1))%8==0)
			;
	else
	{
		for(i;i< (strlen(shuru)-1)/8*8+1+8; i++)//��������
			printf("0");

		printf("\n");
	}

}

int main(void)
{
	char shuru[1000]={0};
	char shuru2[1000]={0};

	gets(shuru);
	gets(shuru2);

	fenge(shuru);
	fenge(shuru2);
		


    system("pause");
    return 0;
}

/*����ʱ�䣺 2016-08-13 13:13:21
  �������⣺ 1.0%N==0 ���� ��0��ʼ���� ���������������ƶ�һλ 2.��ʱ8�ı�����ʱ�����һ��0 ����8�ı�������������ж���
  ���Ĺ��ܣ� ����ֱ����

  ���鹦�ֱܷ��� 1��ӡ��ʼ�����һ��8�ı��� 2.���һ�д�ӡʣ�µ��� 3.�����������
*/