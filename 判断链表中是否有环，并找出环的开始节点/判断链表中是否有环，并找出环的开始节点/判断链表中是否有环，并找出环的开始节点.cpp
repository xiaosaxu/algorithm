/*开始时间： 2016-07-14 14:44:32
实现功能：找环 并找出在那个节点
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

		p1=(Node*)malloc(sizeof(Node));//一定要放在循环里面 没新建一个都要分配内存
		if(p1==NULL) {printf("error");return Head;}
		memset(p1,0,sizeof(Node));

		p1->value=data;
		p1->Next=NULL;//初始化要写好 作为最后的节点

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
	p2->Next=Head->Next->Next;//构成一个环  最后的尾节点的指针不为空 指向前面的某个节点 使用方法为 给p2->Next 赋值
	return Head;
}

int IsCirleList(Node *Head)
{
	Node *p1,*p2;
	int i=0;
	if(Head==NULL)//防止链表为空 程序的健壮性
															/*
													1）预防用户的操作错误 
													2）检查参数的合法性 
													3）不要预先确定限制条件 
													4）先测试后优化

															*/
		return -1;

	p1=Head->Next;
	if(p1==NULL)//判断是否只有一个节点的链表 是则不是循环链表
		return 0;

	p2=Head->Next->Next;//判断是否只有两个节点的链表 是则不是循环链表
	if(p2==NULL)
		return 0;//这样做防止

	while(p1!=p2&&p2!=NULL)//因为p2走得快所以 用p2来判断是否已经走结束
	{
	p1=p1->Next;
	p2=p2->Next->Next;
	}

	if(p1==p2)
		printf("存在环");
	else
		printf("不存在环\n");

	p1=Head;
	while(p1!=p2)
	{
		i++;
		p1=p1->Next;
		p2=p2->Next;
	}

	printf("环起点在第%d个位置\n",i);

}
int main(void)
{
	
	Node *Head=NULL;

	Head=CreatList(Head);

	IsCirleList(Head);

    system("pause");
    return 0;
}

/*结束时间： 2016-07-14 16:06:01
  存在问题：
  核心功能：有环的话两个指针一定会相遇  假设在b相遇 2p1=p2 
													p1=a+b p2=a+b+kN 从而有a+b=kN  p2在b处再走a步肯定会回到起点 且与相遇
*/