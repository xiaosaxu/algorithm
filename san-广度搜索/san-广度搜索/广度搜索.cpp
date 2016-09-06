/*开始时间： 2016-09-06 15:19:05
实现功能：
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
//
typedef struct pso_tag
{
	int x;
	int y;
	int step;
	int father;
}Postion;

int ditu[50][50] = {0};
int book[50][50] = {0};

Postion queue[2500] = {0};
int tail=1,head=1;

int stx=0, sty=0, edx=0, edy=0;
int hang=0, lie=0;
int i,j,k;

int next[4][2]={1,0, 0,1, -1,0, 0,-1};

int main(void)
{
	scanf("%d %d",&hang, &lie);

	for(i=1; i<=hang; i++)
		for(j=1; j<=lie; j++)
			scanf("%d",&ditu[i][j]);

	scanf("%d %d %d %d",&stx, &sty, &edx, &edy);

	queue[tail].x = stx;
	queue[tail].y = sty;
	queue[tail].step = 0;//起始点入队
	tail++;

	book[stx][sty] = 1;//并标记

	while(head < tail)
	{
		for(i=0; i<4; i++)
		{
			int next_x = queue[head].x + next[i][0];
			int next_y = queue[head].y + next[i][1];

			if(next_x < 1 || next_x > lie || next_y < 1 || next_y > hang)//对迷宫而言 这是判断条件 4个方向循环 对循环后的点的有效性和目的性进行判断 
				continue;
			if(book[next_x][next_y] == 0 && ditu[next_x][next_y] == 0)//在图中是要求连接
			{
				queue[tail].x = next_x;
				queue[tail].y = next_y;
				queue[tail].step = queue[head].step + 1;
				book[next_x][next_y] = 1;
				tail ++;//注意这里加一了 对于自加或者自减的变量最后输出的时候一定要看清楚变量的范围 因为改变量加一之后默认的值为 0 
			}

			if(next_x == edx && next_y == edy)
			{
				printf("%d\n",queue[tail-1].step);//这里的输出要是 tail-1 一定要注意自加变量的值
			}
		}

		head ++;
	}

	system("pause");
 
	return 0;

	
}

/*结束时间： 2016-09-06 19:03:12
  存在问题：
  核心功能：对于广度优先算法 在其生成的每个路径点中增加一个 变量来记录路径 把上级的路径传递给他 加上本身的节点  思路：可以使用结构体 里面
  存放路径字符 利用结构体的整体赋值
*/
