// DoubleLink.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*��ʼʱ�䣺 2016-07-30 14:47:27
ʵ�ֹ��ܣ�
1.����˫������ �������Ԫ��ֵ������� ��С����
2.���մ�С����Ĵ�����ԭ�����в���Ԫ��
3.����Ԫ�ص�ֵɾ�������е�ĳ���ڵ�

ע�⣺��������Ĵ���˼��Ҫѧϰ���������� �� ������Ĳ����Ƕ���һ�� pre ָ��
		��ָ���������ֻ�� ����� ɾ�� ���� ����ʾ����  �����ı��� ���� �ȵ� ���Ǻ͵�����һ����

		http://blog.csdn.net/zz198808/article/details/7934427
*/


#include<iostream>
using namespace std;

struct DoubleNode
{
	int data;
	DoubleNode* pre;
	DoubleNode* next;

};

DoubleNode* create_DoubleLink(int a[], int len)
{
	DoubleNode* head,*p,*q;
	p=new DoubleNode();
	p->data=a[0];
	head=p;
	head->pre=NULL;
	for (int i=1;i<len;i++)
	{
		q=new DoubleNode();
		q->data=a[i];
		q->pre=p;
		p->next=q;
		p=q;
	}
	p->next=NULL;
	return head;
}

DoubleNode* deleteTheNode(DoubleNode* head, int num)
{
	DoubleNode *p1;
	p1=head;
	while (p1->next && num!=p1->data)
	{
		p1 = p1->next;
	}
	if (num==p1->data)		//�ж�����Ϊ�ҵ��˳� ���� û�ҵ��˳�
	{
		if (p1==head)//�ҵ�����ͷ�ڵ�
		{
			head=head->next;
			head->pre=NULL;
		}
		else if(p1->next)//����ͷ���,Ҳ����β�ڵ�
		{
			p1->next->pre=p1->pre;
			p1->pre->next=p1->next;
		}
		else
		{
			p1->pre->next=NULL;
		
			free(p1);
		}
	}
	else
	{
		cout<<"�ڵ�δ�ҵ�"<<endl;
	}
	return head;
}

//˳��˫������Ĳ���
DoubleNode* insert(DoubleNode* head,int num)
{
	DoubleNode *p0,*p1;
	p1=head;
	p0=new DoubleNode();
	p0->data=num;
	while (p1->next != NULL && p1->data < p0->data) //�ҵ����ǵ�һ�����ڱ�����Ԫ�ص� ��˲��� ǰ��ķ�ʽ �����ڵ�
	{
		p1=p1->next;
	}
	if (p0->data <= p1->data)			//ȷʵ�ҵ������Ľڵ㣺1.�ýڵ���ͷ�ڵ� 2.�ýڵ����м�ڵ�
	{
		//���p1����ͷ�ڵ�
		if (p1==head)
		{
			p1->pre = p0;
			p0->next = p1;
			p0->pre = NULL;

			head = p0;
		}
		else
		{
			//���p1�����м�Ľڵ�
			p0->next = p1;
			p0->pre = p1->pre;
			p1->pre->next = p0;
			p1->pre = p0;
		}
	}
	else//û���ҵ�����Ҫ��Ľڵ������ǲ�����β�ڵ�
	{
		//˵�����ĸ����� ����β�ڵ�
		p1->next = p0;
		p0->pre = p1;
		p0->next = NULL;
	}

	return head;
}

void PrintDoubleLink(DoubleNode * head)
{
	DoubleNode *p1=head;
	while(p1 != NULL)
	{
		printf("%d ", p1->data);
		p1 = p1->next;
	}
	printf("\n");
}

void Anti_PrintDoubleLink(DoubleNode * PNode)
{
	if(PNode!=NULL)
	{
		Anti_PrintDoubleLink(PNode->next);//ʵ���ϴ��ݽ�ȥ���β�ֵ�Ѿ�������ÿ����ʱ����������
		printf("%d ",PNode->data);
	}

}

int main(void)
{
	int a[]={1,2,4,7,9};
	int len=sizeof(a)/sizeof(int);
	DoubleNode* head=create_DoubleLink(a,len);
	PrintDoubleLink(head);

	head=insert(head, -1);
	PrintDoubleLink(head);

	head=insert(head, 6);
	PrintDoubleLink(head);

	head=insert(head,10);
	PrintDoubleLink(head);

	head = deleteTheNode(head,-1);
	PrintDoubleLink(head);

	Anti_PrintDoubleLink(head);

	
	system("pause");
	return 0;
}

