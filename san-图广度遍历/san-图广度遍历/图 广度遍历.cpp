/*��ʼʱ�䣺 2016-09-06 20:25:59
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>

int dianshu, hangshu;
int ditu[50][50] = {0};
int book[50] = {0};

int a,b,c;
int i,j,k;

int queue[50] = {0};
int head,tail;
int main(void)
{
	scanf("%d %d",&dianshu,&hangshu);

	for(i=1; i<hangshu; i++)
	{
		scanf("%d %d",&a,&b);
		ditu[a][b] = 1;
		ditu[b][a] = 1;
	}

	head = 1;
	tail = 1;

	queue[tail] = 1;
	tail++;
	book[1] = 1;

	while(head < tail)
	{
		for(int i=1;i<=dianshu;i++)
		{
			if(ditu[queue[head]][i] == 1 && book[i] ==0)
			{
				book[i] = 1;
				queue[tail] = i;
				tail++;
			}
		}
		head++;
	}

	for(i=1;i<tail;i++)//����������±�Ҫע�� �������������ʹ�õ�ʲô�±�  ���±�ı仯����Ҫ��Ϥ
		printf("%d",queue[i]);

	system("pause");
	return 0;
}

/*����ʱ�䣺 2016-09-06 20:54:46
  �������⣺
  ���Ĺ��ܣ������Թ��Ĳ���������һ�� ͼ�������ж�������һ������� ���߶�����ʽ�Ĳ�һ��
*/