/*��ʼʱ�䣺 2016-07-11 10:22:37
ʵ�ֹ��ܣ�ð������ �����Ӻ���(�β�����) 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<time.h>
using namespace std;

void jiaohuan(int &a,int &b)//ע��ѽ�����װ�ɺ�����ʱ��Ҫ�ر�ע��ֲ������βε����� Ҫ������ ����ָ�루��ָ������ݽ��н���������ָ�룡��
{
	int temp;
	temp=b;
	b=a;
	a=temp;
}

int kuaipaiyici(int shuzi[],int L,int H)
{
	int temp=shuzi[L];
	while(L<H)
	{
		while(shuzi[H]>temp&&H>L)
			H--;

		shuzi[L]=shuzi[H];

		while(shuzi[L]<temp&&H>L)
			L++;
		
		shuzi[H]=shuzi[L];
	}
	shuzi[H]=temp;
	return H;
}

void kuaipai_f(int shuzu[],int L,int H)
{
	while(L<H)
	{
		int i=kuaipaiyici(shuzu,L,H);
		kuaipaiyici(shuzu,L,i-1);
		kuaipaiyici(shuzu,i+1,H);
	}
}

int main(void)
{
	int maopao[100]={0},kuaipai[100]={0},i,j,temp;
//����������鲿��
    srand((unsigned) time(NULL)); //����ʱ������
	for(i=0;i<100;i++)
	{
		maopao[i]=rand()%50;
		kuaipai[i]=rand()%100;
	}

	for(i=0;i<100;i++)
		printf("%d ",maopao[i]);
	printf("\n");
//ð�����򲿷�
	for(i=0;i<100;i++)
		for(j=1;j<100-i;j++)
			if(maopao[j-1]<maopao[j])//���� �� �����±�����j Ҫע�⣡
			{
				jiaohuan(maopao[j-1],maopao[j]);
			}
	for(i=0;i<100;i++)
		printf("%d ",maopao[i]);
	printf("\n");

	//	ϴ���㷨����ǰ����ÿ��Ԫ�����κ� ���ѡ��һ��Ԫ�ؽ��н���
	for(i=0;i<100;i++)
	{
		temp=rand()%100;
		jiaohuan(maopao[temp],maopao[i]);

	}
	for(i=0;i<100;i++)
		printf("%d ",maopao[i]);
	printf("\n");

	printf("���Ų���\nԭ���ݣ�\n");
//�������򲿷� ���ž���һ��������ӵĹ��� ȡ��һ��������һ������Ҫ��������� ���ѱ����ڸڣ�����

	for(i=0;i<10;i++)
		printf("%d ",kuaipai[i]);
	printf("\n");
	
	kuaipaiyici(kuaipai,0,9);

	for(i=0;i<10;i++)
		printf("%d ",kuaipai[i]);
	printf("\n");
	


    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-07-11 14:03:27
  �������⣺����һ�εĹ���ʵ�� ��ε��ù���Ϊʵ�� һֱ����ѭ�� ���λ����ǲ����Ĵ���������
  ���Ĺ��ܣ�
  int kuaipaiyici(int shuzi[],int L,int H)
{
	int temp=shuzi[L];
	while(L<H)
	{
		while(shuzi[H]>temp&&H>L)
			H--;

		shuzi[L]=shuzi[H];

		while(shuzi[L]<temp&&H>L)
			L++;
		
		shuzi[H]=shuzi[L];
	}
	shuzi[H]=temp;
	return H;
}
*/