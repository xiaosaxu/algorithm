// c++ sort()������ʹ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int comp(int a,int b)
{
	return a<b;
}


typedef struct paixu_tag
{
	int a;
	int b;
}paixu_type;

int comp2(struct paixu_tag &aa,struct paixu_tag &bb)
{
	return aa.a > bb.a ;
}

//����ʹ�� struct paixu_tag aa;  ���� paixu_type �����ṹ�����

int main(void)
{
	paixu_type stt[100]={0};
	
	int shuru[100]={0},i,j;
	for(i=0;i<10;i++)
		scanf("%d",&shuru[i]);//ע�� ����������ַ� %c scanf������� �ո� �س� ���ַ������ȥ

	stable_sort(shuru,shuru+10,comp);//��������ȽϺ���

		for(i=0;i<10;i++)
		printf("%d ",shuru[i]);
		printf("\n ");

		for(i=0;i<100;i++)
			stt[i].a=i;//�ṹ���ʼ��

		sort(stt,stt+100,comp2);//�ṹ������ �������� ��ַ�� ƫ��

			for(i=0;i<100;i++)
			printf("%d ",stt[i].a);



		system("pause");

	return 0;
}

