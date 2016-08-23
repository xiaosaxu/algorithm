// 链表操作.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"//预编译头 没关系
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

int SizeList(Node *Head);//注意 有返回值的函数调用 不能是void型 函数类型一定要与返回值一致

int GetElement(Node * Head,int index);

int FindElement(Node *Head,int Data);

//插入链表有三种方式 1.表头 2.表尾 3.表中间（1.以序号为查找 2.以元素值查找）

Node * InsertHeadElement(Node * Head,int Data);

Node * InsertTailElement(Node * Head,int Data);

Node * InsertIndexElement(Node *Head,int Index,int Data);

Node * InsertDataElement(Node *Head,int Target,int Data);


//删除链表和上面一样有三种 1.删除表头 2.删除表尾 3.删除中间

Node * DeleteHeadElement(Node * Head);

Node * DeleteTailElement(Node * Head);

Node * DeleteIndexElement(Node *Head,int Index);

Node * DeleteDataElement(Node *Head,int Target);

int main(void)
{
	
	Node *Head=NULL;//作为全局变量 链表的头指针 非常重要 之后的函数参数都是传递的这个


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

	printf("链表大小为 %d\n",SizeList(Head));

	printf("链表第三个元素为 %d\n",GetElement(Head,3));

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

	int temp=1;//该元素用来临时存放输入的数 和判断输入终止条件
	Node *p1,*p2;//两个元素分别指向新分配的元素和指向链表的最后一个元素

	while(temp>0)
	{

	p1=(Node *)malloc(sizeof(Node));//p1始终是指向新分配的元素
	if(p1==NULL) {printf("内存分配失败\n");return 0;}
	memset(p1,0,sizeof(Node));

	scanf("%d",&temp);//对新节点进行赋值
	p1->element=temp;
	p1->next=NULL;

	if(Head==NULL)
	{Head=p1;p2=p1;}//赋值的第三步首先判断 不管怎么样为了使得p2始终指向最后一个元素 都要把p2=p1
	else
		//Head->next=p1;//这样处理导致每一次分配只能在下一个 链表的总长度为2
	{p2->next=p1;
		p2=p1;//p2始终指向链表的最后一个元素
	}
	}

	return Head;
   }



 void ListPrint(Node * Head)
   {
    printf("\n链表元素为：\n");
	Node * p1;
	p1=Head;
	while(p1!=NULL)//将原来的p1->next!=NULL 改成这个防止最后一个节点漏掉
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
	printf("已释放链表\n");
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

if(index>id) {printf("超出范围\n");return -2;}//超出范围

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
	if(p1==NULL) {printf("内存分配失败\n"); return Head;}
    memset(p1,0,sizeof(Node));

	p1->element=Data;
	p1->next=Head;
	Head=p1;

	return Head;

}

Node * InsertTailElement(Node * Head,int Data)
{
	Node *p1,*p2;

	p2=Head;//这句话一定要注意 不对变量进行赋值直接使用 显然是错的
	while(p2->next!=NULL)
	{
	p2=p2->next;//查找出表尾最后一个元素
	}

	p1=(Node *)malloc(sizeof(Node));
	if(p1==NULL) {printf("内存分配失败"); return Head;}
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

  //可以对输入的序号判断 包含1.大于等于1 超出范围等

	p1=(Node*)malloc(sizeof(Node));
	if(p1==NULL) {printf("内存分配失败");return Head;}
	memset(p1,0,sizeof(Node));//分配

	p1->element=Data;//赋值

	p1->next=p2->next;//插入 p1是新元素 p2是目标位置
	p2->next=p1;

	return Head;
}


Node * InsertDataElement(Node *Head,int Target,int Data)
{
	Node *p1,*p2=Head;


	while(p2!=NULL)//防止查找不到 先找 再分节点内存
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

Node * DeleteIndexElement(Node *Head,int Index)//注意 删除是找他上一个节点和当前节点 插入是找下一个节点和当前节点
{
	Node *p1=Head,*p2;
	int i=0;

	while(p1!=NULL)
	{

		p2=p1;		//p2表示当前的找到的节点 p1是指向下一个的节点
		p1=p1->next;

		i++;		//默认从1序号开始
		if(Index-1==i)//因为默认查找到的元素是当前元素和该元素的下一个元素，删除不方便 因此使用节点减一操作
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

	while(p1!=NULL)//有bug版 没有该元素时候p1->element错误 空地址
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