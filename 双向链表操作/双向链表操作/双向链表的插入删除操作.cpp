// DoubleLink.cpp : 定义控制台应用程序的入口点。
//

/*开始时间： 2016-07-30 14:47:27
实现功能：
1.创建双向链表 该链表的元素值是有序的 从小到大
2.按照从小到大的次序向原链表中插入元素
3.按照元素的值删除链表中的某个节点

注意：该种问题的处理思想要学习到单链表中 和 单链表的差距就是多了一个 pre 指针
		该指针的特殊性只在 链表的 删除 插入 中显示出来  其他的遍历 查找 等等 都是和单链表一样的

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
	if (num==p1->data)		//判断是因为找到退出 还是 没找到退出
	{
		if (p1==head)//找到的是头节点
		{
			head=head->next;
			head->pre=NULL;
		}
		else if(p1->next)//不是头结点,也不是尾节点
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
		cout<<"节点未找到"<<endl;
	}
	return head;
}

//顺序双向链表的插入
DoubleNode* insert(DoubleNode* head,int num)
{
	DoubleNode *p0,*p1;
	p1=head;
	p0=new DoubleNode();
	p0->data=num;
	while (p1->next != NULL && p1->data < p0->data) //找到的是第一个大于被插入元素的 因此采用 前插的方式 操作节点
	{
		p1=p1->next;
	}
	if (p0->data <= p1->data)			//确实找到这样的节点：1.该节点是头节点 2.该节点是中间节点
	{
		//如果p1就是头节点
		if (p1==head)
		{
			p1->pre = p0;
			p0->next = p1;
			p0->pre = NULL;

			head = p0;
		}
		else
		{
			//如果p1就是中间的节点
			p0->next = p1;
			p0->pre = p1->pre;
			p1->pre->next = p0;
			p1->pre = p0;
		}
	}
	else//没有找到符合要求的节点所以是插入在尾节点
	{
		//说明比哪个都大 插入尾节点
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
		Anti_PrintDoubleLink(PNode->next);//实际上传递进去的形参值已经保存在每个临时变量里面了
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

