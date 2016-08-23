// �������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"//Ԥ����ͷ û��ϵ
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
int element;

struct node * next;

}Node;


Node * CreatList(Node* Head);

void ListPrint(Node * Head);

void ClearList(Node *Head);

int SizeList(Node *Head);//ע�� �з���ֵ�ĺ������� ������void�� ��������һ��Ҫ�뷵��ֵһ��

int GetElement(Node * Head,int index);

int FindElement(Node *Head,int Data);

//�������������ַ�ʽ 1.��ͷ 2.��β 3.���м䣨1.�����Ϊ���� 2.��Ԫ��ֵ���ң�

Node * InsertHeadElement(Node * Head,int Data);

Node * InsertTailElement(Node * Head,int Data);

Node * InsertIndexElement(Node *Head,int Index,int Data);

Node * InsertDataElement(Node *Head,int Target,int Data);


//ɾ�����������һ�������� 1.ɾ����ͷ 2.ɾ����β 3.ɾ���м�

Node * DeleteHeadElement(Node * Head);

Node * DeleteTailElement(Node * Head);

Node * DeleteIndexElement(Node *Head,int Index);

Node * DeleteDataElement(Node *Head,int Target);

int main(void)
{
	
	Node *Head=NULL;//��Ϊȫ�ֱ��� �����ͷָ�� �ǳ���Ҫ ֮��ĺ����������Ǵ��ݵ����


	Head=CreatList(Head);

	Head=DeleteHeadElement(Head);

	Head=DeleteTailElement(Head);


	Head=DeleteDataElement(Head,13);

	Head=InsertHeadElement( Head,255);

	Head=InsertTailElement(Head,255);

	Head=InsertIndexElement(Head,2,255);

	Head=InsertDataElement(Head,12,255);

	ListPrint(Head);

	Head=DeleteIndexElement(Head,3);

	ListPrint(Head);

	printf("�����СΪ %d\n",SizeList(Head));

	printf("���������Ԫ��Ϊ %d\n",GetElement(Head,3));

	if(FindElement(Head,4)==1)
		printf("\nfind element 4\n");
	else
		printf("\nnot find element 4\n");


	ClearList(Head);


	system("pause");

	return 0;
}




Node * CreatList(Node* Head)
   {
	printf("inpute linked list:\n");

	int temp=1;//��Ԫ��������ʱ���������� ���ж�������ֹ����
	Node *p1,*p2;//����Ԫ�طֱ�ָ���·����Ԫ�غ�ָ����������һ��Ԫ��

	while(temp>0)
	{

	p1=(Node *)malloc(sizeof(Node));//p1ʼ����ָ���·����Ԫ��
	if(p1==NULL) {printf("�ڴ����ʧ��\n");return 0;}
	memset(p1,0,sizeof(Node));

	scanf("%d",&temp);//���½ڵ���и�ֵ
	p1->element=temp;
	p1->next=NULL;

	if(Head==NULL)
	{Head=p1;p2=p1;}//��ֵ�ĵ����������ж� ������ô��Ϊ��ʹ��p2ʼ��ָ�����һ��Ԫ�� ��Ҫ��p2=p1
	else
		//Head->next=p1;//����������ÿһ�η���ֻ������һ�� ������ܳ���Ϊ2
	{p2->next=p1;
		p2=p1;//p2ʼ��ָ����������һ��Ԫ��
	}
	}

	return Head;
   }



 void ListPrint(Node * Head)
   {
    printf("\n����Ԫ��Ϊ��\n");
	Node * p1;
	p1=Head;
	while(p1!=NULL)//��ԭ����p1->next!=NULL �ĳ������ֹ���һ���ڵ�©��
	{ 
	printf("%d\n",p1->element);
	p1=p1->next;
	}
   
   }




void ClearList(Node *Head)
{

	Node *p1,*p2;
	p1=Head;
	
	if(p1==NULL)
	{printf("KONG\n");return ;}
	else 
	{
	while(p1!=NULL)
	{	
	p2=p1->next;
	free(p1);
	p1=p2;
	}
	printf("���ͷ�����\n");
	}
}


int SizeList(Node *Head)
{

Node *p1=Head;
int size=0;

while(p1!=NULL)
{
p1=p1->next;
size++;
}

return size;
}

int GetElement(Node * Head,int index)
{
Node *p1=Head;
int id=0;

if(index<1) {printf("index error\n");return -2;}
if(p1==NULL) {printf("lianbiao kong\n");return -2;}
while(p1!=NULL)
{
id++;
if(id==index)
break;

p1=p1->next;

}

if(index>id) {printf("������Χ\n");return -2;}//������Χ

return p1->element;

}

int FindElement(Node *Head,int Data)
{
Node * p1=Head;

while(p1!=NULL)
{
if(p1->element==Data)
break;
p1=p1->next;
}
if(p1!=NULL)
return 1;
else
return 0;

}

Node * InsertHeadElement(Node * Head,int Data)
{
	Node *p1;

	p1=(Node *)malloc(sizeof(Node));
	if(p1==NULL) {printf("�ڴ����ʧ��\n"); return Head;}
    memset(p1,0,sizeof(Node));

	p1->element=Data;
	p1->next=Head;
	Head=p1;

	return Head;

}

Node * InsertTailElement(Node * Head,int Data)
{
	Node *p1,*p2;

	p2=Head;//��仰һ��Ҫע�� ���Ա������и�ֱֵ��ʹ�� ��Ȼ�Ǵ��
	while(p2->next!=NULL)
	{
	p2=p2->next;//���ҳ���β���һ��Ԫ��
	}

	p1=(Node *)malloc(sizeof(Node));
	if(p1==NULL) {printf("�ڴ����ʧ��"); return Head;}
	memset(p1,0,sizeof(Node));

	p1->element=Data;

	p2->next=p1;

	return Head;
}

Node * InsertIndexElement(Node *Head,int Index,int Data)
{
	Node * p1,*p2;
	int i=0;

	p2=Head;
	while(p2!=NULL)
	{
		i++;
		if(Index==i)
			break;
		p2=p2->next;
	}

  //���Զ����������ж� ����1.���ڵ���1 ������Χ��

	p1=(Node*)malloc(sizeof(Node));
	if(p1==NULL) {printf("�ڴ����ʧ��");return Head;}
	memset(p1,0,sizeof(Node));//����

	p1->element=Data;//��ֵ

	p1->next=p2->next;//���� p1����Ԫ�� p2��Ŀ��λ��
	p2->next=p1;

	return Head;
}


Node * InsertDataElement(Node *Head,int Target,int Data)
{
	Node *p1,*p2=Head;


	while(p2!=NULL)//��ֹ���Ҳ��� ���� �ٷֽڵ��ڴ�
	{
	if(p2->element==Target)
		break;
	p2=p2->next;
	
	}

	if(p2==NULL) {printf("Not Find %d cannt insert\n",Target);return Head;}

	p1=(Node*)malloc(sizeof(Node));
	if(p1==NULL) {printf("failed");return Head;}
	memset(p1,0,sizeof(Node));

	p1->element=Data;


	p1->next=p2->next;
	p2->next=p1;

	return Head;

}

Node * DeleteHeadElement(Node * Head)
{
	Node *p1;

	p1=Head;
	Head=Head->next;
	free(p1);

	return Head;
}

Node * DeleteTailElement(Node * Head)
{
	Node * p1,*p2;

	p1=Head;
	while(p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}

	p2->next=NULL;
	free(p1);

	return Head;

}

Node * DeleteIndexElement(Node *Head,int Index)//ע�� ɾ����������һ���ڵ�͵�ǰ�ڵ� ����������һ���ڵ�͵�ǰ�ڵ�
{
	Node *p1=Head,*p2;
	int i=0;

	while(p1!=NULL)
	{

		p2=p1;		//p2��ʾ��ǰ���ҵ��Ľڵ� p1��ָ����һ���Ľڵ�
		p1=p1->next;

		i++;		//Ĭ�ϴ�1��ſ�ʼ
		if(Index-1==i)//��ΪĬ�ϲ��ҵ���Ԫ���ǵ�ǰԪ�غ͸�Ԫ�ص���һ��Ԫ�أ�ɾ�������� ���ʹ�ýڵ��һ����
		{break;}
			
	}

	p2->next=p1->next;
	free(p1);

	return Head;


}

Node * DeleteDataElement(Node *Head,int Target)
{
	Node *p1,*p2;
	p1=Head;

	while(p1!=NULL)//��bug�� û�и�Ԫ��ʱ��p1->element���� �յ�ַ
	{
		p2=p1;
		p1=p1->next;

		if(p1->element==Target)
			break;
	}

	if(p1==NULL) {printf("cannot fint %d cannot deletl\n",Target);return Head;}

	p2->next=p1->next;

	free(p1);

	return Head;
}