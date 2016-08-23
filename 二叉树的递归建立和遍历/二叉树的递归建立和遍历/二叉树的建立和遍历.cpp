/*��ʼʱ�䣺 2016-08-01 09:12:35
ʵ�ֹ��ܣ�
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

void createBiTree(BiTreeNode *  &T)//Լ����ǰ������ķ�ʽ����������
{//ע����Ϊ��ΪT��ֵҲ�ı��� ����ָ��Ļ����Ըı�ָ��ָ������� ���ı�ָ�뱾��ֵ ��Ϊ��ʱ����  
	//���Ǳ����ж�ָ�뱾������ݸı��� ������Ҫʹ��ָ���Ӧ�� ��������������Ҳ�ı��� ����ʹ����return��������ʱ������ֵ��
	char c;
	scanf("%c",&c);

	if('#'==c)
		T=NULL;//ִ�и����֮���˳�
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

void visit(char c,int level)//���ʶ������ľ������ ������ʲô
{
	printf("%c �ڵ� %d ��\n",c,level);
}

//����������
void PreOrder(BiTreeNode * T,int level)
{
	if(T)
	{
		
		visit(T->data,level);//ע�� ֱ�Ӹı���ʵ�˳�����ʵ�� ǰ�к� �����
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