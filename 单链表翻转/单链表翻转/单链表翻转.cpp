/*开始时间： 2016-07-12 10:18:37
实现功能：
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
		if(data<0) break;//对读取的值进行判断

		p1=(Node *)malloc(sizeof(Node));//注意 对于p1->next形式的表达 如果未分配内存则会引发错误 因为指针没有明确指向 需要先分配内存 在执行这样的操作！
											   //或者虽然没有分配，但是把他指向了已经分配好的内存空间也是可以的
		if(p1==NULL) {printf("malloc error");return Head;}

		
		p1->value=data;
		p1->next=NULL;
		
		if(Head==NULL)
		{
			Head=p1;//注意这才是head的用法 直接 而不是heah->next
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
	printf("一共有%d个节点\n",ListTotal);
}

Node * Reverselist(Node *Head)
{
	Node *cp,*np,*nnp;
	cp=Head;
	np=cp->next;//先保存 再在后面赋值
	cp->next=NULL;//第一个最后作为尾节点所以要赋值为NULL

	while(np)
	{
		nnp=np->next;//保存np下一个节点

		np->next=cp;//真正执行的有效部分  把已经翻转的作为整体 接在新节点的后面

		cp=np;
		np=nnp;

	}
	return cp;

}

Node * InsertList(Node * Head,int index,int data)//需要创建两个临时变量 一个用来给新建待插入的节点 另一个用来遍历的节点变量
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

	if(index==0)//插入头
	{
		p1->next=Head;
		Head=p1;
	}
	else
	{
		while(i<index)//i 从1 开始的 一致
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
	int i=2;// 调整大小 用于定位删除节点的前一个节点
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
		p1->next=p1->next->next;//这种思路是非常好的 只要找到删除节点前面的一个节点就可以了（已测试头结点 中间 尾部节点 通过）
		free(p2);

	}
	return Head;
}

int main(void)
{
	Node * Head=NULL;//全局变量 保证在所有的函数中 通用 唯一 
	//Head->next=NULL;
	

	Head=CreatList(Head);

	PrintList(Head);

	Head=Reverselist(Head);

	PrintList(Head);

	Head=InsertList(Head,ListTotal,-99);//注意修改头指针一定要返回 否则不会变

	PrintList(Head);

	Head=NodeDelet(Head,ListTotal);

	PrintList(Head);

	system("pause");
}

/*结束时间： 2016-07-12 14:22:00
  存在问题：要知道 每个子功能实现需要哪些临时变量 插入节点要知道插入那一个节点 删除节点要知道删除节点的上一个节点
			返回Head不仅在子函数里面返回 调用后要返回给原来的Head  Head=InsertList(Head,ListTotal,-99);
  核心功能：翻转
				  while(np)
					{
						nnp=np->next;//保存np下一个节点

						np->next=cp;//真正执行的有效部分

						cp=np;
						np=nnp;

					}

		删除
		p2=p1->next;
		p1->next=p1->next->next;//这种思路是非常好的 只要找到删除节点前面的一个节点就可以了（已测试头结点 中间 尾部节点 通过）
		free(p2);
		
		插入
		p1->next=p2->next;
		p2->next=p1;

*/