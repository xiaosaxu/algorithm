/*开始时间： 2016-08-01 09:12:35
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;


typedef struct Node
{
	char data;
	struct Node *left;
	struct Node *right;
}BiTreeNode;

void createBiTree(BiTreeNode *  &T)//约定用前序遍历的方式创建二叉树
{//注意因为把为T的值也改变了 传递指针的话可以改变指针指向的内容 不改变指针本身值 作为临时变量  
	//但是本例中对指针本身的内容改变了 所以需要使用指针的应用 （我们在链表中也改变了 但是使用了return返回了临时变量的值）
	char c;
	scanf("%c",&c);

	if('#'==c)
		T=NULL;//执行该语句之后退出
	else
	{
		T = (BiTreeNode *)malloc(sizeof(BiTreeNode));
		if(NULL == T)
			exit(0);
		memset(T, 0, sizeof(BiTreeNode) );

		T->data = c;
		createBiTree(T->left);
		createBiTree(T->right);
	}
}

void visit(char c,int level)//访问二叉树的具体操作 你想做什么
{
	printf("%c 在第 %d 层\n",c,level);
}

//遍历二叉树
void PreOrder(BiTreeNode * T,int level)
{
	if(T)
	{
		
		visit(T->data,level);//注意 直接改变访问的顺序可以实现 前中后 序遍历
		PreOrder(T->left,level+1);
		PreOrder(T->right,level+1);
		
	}
}

int main(void)
{
    BiTreeNode *T = NULL;
	int level = 1;

	createBiTree(T);

	PreOrder(T,level);

    system("pause");

    return 0;
}