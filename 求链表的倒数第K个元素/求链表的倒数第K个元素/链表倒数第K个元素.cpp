/*��ʼʱ�䣺 2016-07-14 20:06:18
ʵ�ֹ��ܣ����� ��������+��������+������K���ڵ�
		  ��� ��������K���ڵ��ֵ
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct NodeList
{
	int data;
	struct NodeList *next;
}Node;

Node *CreatList(Node * Head,int num)
{
	Node *p1,*p2;
	int i,value;
	for(i=0;i<num;i++)
	{
		scanf("%d",&value);
		p1=(Node*)malloc(sizeof(Node));
		if(p1==NULL)
		{
			printf("error\n");
			return Head;
		}

		p1->data=value;
		p1->next=NULL;

		if(Head==NULL)
		{
			Head=p1;
			p2=p1;
		}
		else
		{
			p2->next=p1;
			p2=p1;
		}
	}

	return Head;
}
 
int FindNodeK(Node * Head,int K)
{
	Node *p1,*p2;
	int i;
	p1=p2=Head;
	for(i=0;i<K;i++)
		p2=p2->next;

	while(p2->next!=NULL)
	{
		p1=p1->next;
		p2=p2->next;

	}

	return p1->data;
}
int main(void)
{
    int num,K;
	Node * Head=NULL;

	scanf("%d",&num);

	Head=CreatList(Head,num);

	scanf("%d",&K);

	printf("%d\n",FindNodeK(Head,K));

    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-07-14 20:26:17
  �������⣺
  ���Ĺ��ܣ�����ָ�� ���K��λ�ã�һ���ߵ���β ʣ�µ�Ϊ������K��
*/