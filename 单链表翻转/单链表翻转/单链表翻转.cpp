/*��ʼʱ�䣺 2016-07-12 10:18:37
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef struct nodelist
{
	int value;
	struct nodelist *next;

}Node;

int ListTotal=0;

Node * CreatList(Node *Head)
{
	int data=0;
	Node *p1,*p2;
	while(1)
	{
		scanf("%d",&data);
		if(data<0) break;//�Զ�ȡ��ֵ�����ж�

		p1=(Node *)malloc(sizeof(Node));//ע�� ����p1->next��ʽ�ı�� ���δ�����ڴ������������ ��Ϊָ��û����ȷָ�� ��Ҫ�ȷ����ڴ� ��ִ�������Ĳ�����
											   //������Ȼû�з��䣬���ǰ���ָ�����Ѿ�����õ��ڴ�ռ�Ҳ�ǿ��Ե�
		if(p1==NULL) {printf("malloc error");return Head;}

		
		p1->value=data;
		p1->next=NULL;
		
		if(Head==NULL)
		{
			Head=p1;//ע�������head���÷� ֱ�� ������heah->next
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

void PrintList(Node *Head)
{
	Node *p1=Head;
	ListTotal=0;
	while(p1)
	{
	ListTotal++;
	printf("%d ",p1->value);
	p1=p1->next;
	}
	printf("һ����%d���ڵ�\n",ListTotal);
}

Node * Reverselist(Node *Head)
{
	Node *cp,*np,*nnp;
	cp=Head;
	np=cp->next;//�ȱ��� ���ں��渳ֵ
	cp->next=NULL;//��һ�������Ϊβ�ڵ�����Ҫ��ֵΪNULL

	while(np)
	{
		nnp=np->next;//����np��һ���ڵ�

		np->next=cp;//����ִ�е���Ч����  ���Ѿ���ת����Ϊ���� �����½ڵ�ĺ���

		cp=np;
		np=nnp;

	}
	return cp;

}

Node * InsertList(Node * Head,int index,int data)//��Ҫ����������ʱ���� һ���������½�������Ľڵ� ��һ�����������Ľڵ����
{
	int i=1;
	Node*p1=NULL,*p2=Head;

	if(index>ListTotal||index<0)
	{printf("index error");return Head;}

	p1=(Node*)malloc(sizeof(Node));
		if(p1==NULL)
		{printf("malloc error");return Head;}

	p1->next=NULL;
	p1->value=data;

	if(index==0)//����ͷ
	{
		p1->next=Head;
		Head=p1;
	}
	else
	{
		while(i<index)//i ��1 ��ʼ�� һ��
		{
			i++;
			p2=p2->next;
		}

		p1->next=p2->next;
		p2->next=p1;
	}

	return Head;
}

Node * NodeDelet(Node * Head,int index)
{
	int i=2;// ������С ���ڶ�λɾ���ڵ��ǰһ���ڵ�
	Node * p1=Head,*p2;
	if(index<1||index>ListTotal)
	{printf("index error");return Head;}

	if(1==index)
	{
		p1=Head;
		Head=Head->next;
		free(p1);
	}
	else
	{
		while(i<index)
		{
			p1=p1->next;
			i++;
		}
		p2=p1->next;
		p1->next=p1->next->next;//����˼·�Ƿǳ��õ� ֻҪ�ҵ�ɾ���ڵ�ǰ���һ���ڵ�Ϳ����ˣ��Ѳ���ͷ��� �м� β���ڵ� ͨ����
		free(p2);

	}
	return Head;
}

int main(void)
{
	Node * Head=NULL;//ȫ�ֱ��� ��֤�����еĺ����� ͨ�� Ψһ 
	//Head->next=NULL;
	

	Head=CreatList(Head);

	PrintList(Head);

	Head=Reverselist(Head);

	PrintList(Head);

	Head=InsertList(Head,ListTotal,-99);//ע���޸�ͷָ��һ��Ҫ���� ���򲻻��

	PrintList(Head);

	Head=NodeDelet(Head,ListTotal);

	PrintList(Head);

	system("pause");
}

/*����ʱ�䣺 2016-07-12 14:22:00
  �������⣺Ҫ֪�� ÿ���ӹ���ʵ����Ҫ��Щ��ʱ���� ����ڵ�Ҫ֪��������һ���ڵ� ɾ���ڵ�Ҫ֪��ɾ���ڵ����һ���ڵ�
			����Head�������Ӻ������淵�� ���ú�Ҫ���ظ�ԭ����Head  Head=InsertList(Head,ListTotal,-99);
  ���Ĺ��ܣ���ת
				  while(np)
					{
						nnp=np->next;//����np��һ���ڵ�

						np->next=cp;//����ִ�е���Ч����

						cp=np;
						np=nnp;

					}

		ɾ��
		p2=p1->next;
		p1->next=p1->next->next;//����˼·�Ƿǳ��õ� ֻҪ�ҵ�ɾ���ڵ�ǰ���һ���ڵ�Ϳ����ˣ��Ѳ���ͷ��� �м� β���ڵ� ͨ����
		free(p2);
		
		����
		p1->next=p2->next;
		p2->next=p1;

*/