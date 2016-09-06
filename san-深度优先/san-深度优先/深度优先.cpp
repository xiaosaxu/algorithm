/*开始时间： 2016-09-06 14:37:35
实现功能：
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int ditu[50][50]={0};
int book[50][50]={0};
int hang = 0, lie = 0;
int i = 0,j = 0,k = 0; 
int stx=0,sty=0,edx=0,edy=0;

int next[4][2]={1,0, 0,1, -1,0, 0,-1};//分别为 右 下 左 上
int minstep = 99;


void DFS(int x, int y, int step)
{
	if(x == edx && y == edy)
	{
		if(step < minstep)
			minstep = step;//深度优先通过递归的深度记录走过的步数 广度优先通过每一层的次数 在结构体里面有这个变量

		return ;
	}
	else
	{
		for(int i=0; i<4; i++)
		{
			int next_x = x + next[i][0];//注意这里是要新建临时变量的 每次循环要基于之前的值改变坐标大小
			int next_y = y + next[i][1];

			if(next_x < 1 || next_x > lie || next_y < 1 || next_y > hang)
				continue;

			if(book[next_x][next_y] == 0 && ditu[next_x][next_y] == 0)//0 表示未访问 可走
			{
				book[next_x][next_y] = 1;
				DFS(next_x, next_y,step+1 );
				book[next_x][next_y] = 0;
			}

		}
	}
}

int main(void)
{


	scanf("%d %d",&hang,&lie);

	for(i=1; i<=hang; i++)
		for(j=1; j<=lie; j++)
			scanf("%d",&ditu[i][j]);//输入的处理也是比较重要的

	scanf("%d %d %d %d",&stx,&sty,&edx,&edy);//程序输入完成

	book[stx][sty] = 1;//标记起点

	DFS(stx, sty, 0);//从起始点出发 所以step是0 

	printf("%d\n",minstep);


	system("pause");

	return 0;
				
		
}

/*结束时间： 2016-09-06 15:14:05
  存在问题：
  核心功能：
*/