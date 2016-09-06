/*开始时间： 2016-09-06 19:38:35
实现功能：输入城市之间能通的节点 输出 深度优先遍历和广度优先遍历的结果
*/

#include<stdio.h>
#include<stdlib.h>

	int ditu[50][50] = {0};
	int book[50] = {0};
	int dianshu = 0,bianshu = 0;
	int i,j,k;
	int a,b,c;

void DFS(int num, int step)
{
	printf("%d",num);
	if(step == dianshu)//实际上这个变量是控制递归深度 并不难呢个保证深度等于点数是遍历完
		return ;
	else
	{
		for(int i=1; i<=dianshu; i++)//注意 递归里面的循环变量一定是局部变量 否则不能递归 会出问题
		{
			if(ditu[num][i] == 1 && book[i] == 0)
			{
				book[i] = 1;
				DFS(i, step+1);
			}

		}
	}
}

int main(void)
{


	scanf("%d %d",&dianshu,&bianshu);

	for(i=1; i<=bianshu; i++)
	{
		scanf("%d %d",&a,&b);
		ditu[a][b] = 1;
		ditu[b][a] = 1;
	}
	for(i=1; i<=dianshu; i++)
		ditu[i][i] = 0;

	book[1] = 1;
	DFS(1,0);

	system("pause");
}

/*结束时间： 2016-09-06 20:22:41
  存在问题：
  核心功能： 递归时直接用点的序号进行递归
			ditu[num][i] == 1 && book[i] == 0 以起点为二维宿主的判断标准 看是否连接  终点是改点 看是否在book数组中
*/