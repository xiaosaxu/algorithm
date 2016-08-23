/*开始时间： 2016-07-14 20:06:18
实现功能：输入 ：链表长度+链表内容+倒数第K个节点
		  输出 ：倒数第K个节点的值
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
/*结束时间： 2016-07-14 20:26:17
  存在问题：
  核心功能：两个指针 相差K个位置，一起走到表尾 剩下的为倒数第K个
*/