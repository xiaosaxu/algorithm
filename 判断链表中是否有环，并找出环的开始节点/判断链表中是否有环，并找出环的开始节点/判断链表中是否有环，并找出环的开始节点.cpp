/*��ʼʱ�䣺 2016-07-14 14:44:32
ʵ�ֹ��ܣ��һ� ���ҳ����Ǹ��ڵ�
*/

\
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct NodeList
{
	int value;
	struct NodeList *Next;
}Node;


Node * CreatList(Node *Head )
{
	Node * p1,*p2;
	int data;
	while(Head==NULL)
		return ;

	while(1)
	{
		scanf("%d",&data);
		if (data < 0) break;

		p1=(Node*)malloc(sizeof(Node));//һ��Ҫ����ѭ������ û�½�һ����Ҫ�����ڴ�
		if(p1==NULL) {printf("error");return Head;}
		memset(p1,0,sizeof(Node));

		p1->value=data;
		p1->Next=NULL;//��ʼ��Ҫд�� ��Ϊ���Ľڵ�

		if(Head==NULL)
		{
			Head=p1;
			p2=p1;
		}
		else
		{
			p2->Next=p1;
			p2=p1;
		}

	}
	p2->Next=Head->Next->Next;//����һ����  ����β�ڵ��ָ�벻Ϊ�� ָ��ǰ���ĳ���ڵ� ʹ�÷���Ϊ ��p2->Next ��ֵ
	return Head;
}

int IsCirleList(Node *Head)
{
	Node *p1,*p2;
	int i=0;
	if(Head==NULL)//��ֹ����Ϊ�� ����Ľ�׳��
															/*
													1��Ԥ���û��Ĳ������� 
													2���������ĺϷ��� 
													3����ҪԤ��ȷ���������� 
													4���Ȳ��Ժ��Ż�

															*/
		return -1;

	p1=Head->Next;
	if(p1==NULL)//�ж��Ƿ�ֻ��һ���ڵ������ ������ѭ������
		return 0;

	p2=Head->Next->Next;//�ж��Ƿ�ֻ�������ڵ������ ������ѭ������
	if(p2==NULL)
		return 0;//��������ֹ

	while(p1!=p2&&p2!=NULL)//��Ϊp2�ߵÿ����� ��p2���ж��Ƿ��Ѿ��߽���
	{
	p1=p1->Next;
	p2=p2->Next->Next;
	}

	if(p1==p2)
		printf("���ڻ�");
	else
		printf("�����ڻ�\n");

	p1=Head;
	while(p1!=p2)
	{
		i++;
		p1=p1->Next;
		p2=p2->Next;
	}

	printf("������ڵ�%d��λ��\n",i);

}
int main(void)
{
	
	Node *Head=NULL;

	Head=CreatList(Head);

	IsCirleList(Head);

    system("pause");
    return 0;
}

/*����ʱ�䣺 2016-07-14 16:06:01
  �������⣺
  ���Ĺ��ܣ��л��Ļ�����ָ��һ��������  ������b���� 2p1=p2 
													p1=a+b p2=a+b+kN �Ӷ���a+b=kN  p2��b������a���϶���ص���� ��������
*/