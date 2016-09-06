/*开始时间： 2016-09-06 20:25:59
实现功能：
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

	for(i=1;i<tail;i++)//对于这里的下标要注意 整个程序过程中使用的什么下标  对下标的变化过程要熟悉
		printf("%d",queue[i]);

	system("pause");
	return 0;
}

/*结束时间： 2016-09-06 20:54:46
  存在问题：
  核心功能：由于迷宫的产生条件不一样 图的链接判断条件不一样造成了 两者队列形式的不一样
*/