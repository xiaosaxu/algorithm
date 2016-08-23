/*开始时间： 2016-07-21 08:52:58
实现功能：根据目前学习的字母数量 随机生成 N 个单词的字符串
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<time.h>
using namespace std;

typedef struct node
{
	char *word;
	struct node *next;
}Node;

Node * InsertNode(Node *Head,char *New)
{
	Node *p1,*p2;
	p1=(Node *)malloc(sizeof(Node));
	p1->word=New;
	p1->next=NULL;

	if(Head==NULL)
	{
		Head=p1;
		
	}
	else
	{//插入表头
		p1->next=Head;
		Head=p1;
	}

	return Head;
}

int main(void)
{
    int DanCiLen,i,Num,j;
	char ZiMu[]="asdfecrtuyiolnh",shuruflag;
	char * Newp,*shuru=ZiMu;
	Node * Head=NULL,*p1,*p2;//指针最好初始化为NULL
	while(1)
	{
		Head=NULL;
		printf("欢迎使用单词生成程序！\n\n请输入你想要生成单词的所有字母：\n输入0使用默认值，默认为：asdfecrtuyiolnh\n输入1使用自定义值\n输入q退出程序\n");
		scanf("%c",&shuruflag);
		if(shuruflag=='0')
			;
		else
			if(shuruflag=='1') {printf("请输入你想要联系的字母集合：\n");scanf("%s",ZiMu);}
		else
			if(shuruflag=='q') break;
		else
			continue ;


		printf("请输入想要生成的单词数量：\n");
		scanf("%d",&Num);

		srand((unsigned int)time(NULL));
			

		for(j=0;j<Num;j++)
		{
			DanCiLen=rand()%4+3;
			Newp=(char *)malloc(DanCiLen+1);
			for(i=0;i<DanCiLen;i++)
			{
				Newp[i]=ZiMu[rand()%strlen(ZiMu)];
			}
			Newp[DanCiLen]='\0';


			Head=InsertNode(Head,Newp);
		
		}

		p1=Head;
		printf("\n\n");
		while(p1!=NULL)
		{
			printf("%s ",p1->word);
			p1=p1->next;
		}
		printf("\n\n");

		/*
		p1=Head;
		
		while(p1!=NULL)
		{
			p2=p1->next;
			free(p1->word);
			free(p1);
			p1=p2;
		}
		*/
	}
    system("pause");
    return 0;
}