/*��ʼʱ�䣺 2016-07-21 08:52:58
ʵ�ֹ��ܣ�����Ŀǰѧϰ����ĸ���� ������� N �����ʵ��ַ���
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
	{//�����ͷ
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
	Node * Head=NULL,*p1,*p2;//ָ����ó�ʼ��ΪNULL
	while(1)
	{
		Head=NULL;
		printf("��ӭʹ�õ������ɳ���\n\n����������Ҫ���ɵ��ʵ�������ĸ��\n����0ʹ��Ĭ��ֵ��Ĭ��Ϊ��asdfecrtuyiolnh\n����1ʹ���Զ���ֵ\n����q�˳�����\n");
		scanf("%c",&shuruflag);
		if(shuruflag=='0')
			;
		else
			if(shuruflag=='1') {printf("����������Ҫ��ϵ����ĸ���ϣ�\n");scanf("%s",ZiMu);}
		else
			if(shuruflag=='q') break;
		else
			continue ;


		printf("��������Ҫ���ɵĵ���������\n");
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