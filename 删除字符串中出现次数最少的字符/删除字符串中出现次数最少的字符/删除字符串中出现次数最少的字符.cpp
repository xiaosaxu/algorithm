// ɾ���ַ����г��ִ������ٵ��ַ�.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

int main(void)
{

	char shuru[30]={0};
	int book[255]={0},book2[255]={0},i,j;

	scanf("%s",shuru);

	for(i=0;i<strlen(shuru);i++)
	{
		book[shuru[i]]++;
		book2[shuru[i]]++;//��һ�����б��� ��Ϊbook1���������˳��ı�
	}

	sort(book,book+255);//�������sort���� �����˱�д����ʱ��

	for(i=0;i<255;i++)
	{
	//printf("%d ",book[i]);
	if(book[i]>0)//�ҵ�Ƶ����С������
		{
			j=book[i];
			break;
		}
	}

	for(i=0;i<strlen(shuru);i++)
	{
		if(book2[shuru[i]]>j)//Ƶ�ʴ��ڲŻ���� �������
			printf("%c",shuru[i]);
	}
    printf("\n");
//	system("pause");

	return 0;
}

