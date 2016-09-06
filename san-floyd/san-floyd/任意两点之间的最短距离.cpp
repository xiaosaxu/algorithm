/*开始时间： 2016-09-06 21:21:23
实现功能：
*/
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int dianshu,bianshu;
	int ditu[50][50] = {0};//注意赋值过程不能
	int a,b,c;
	int i,j,k;
	scanf("%d %d",&dianshu,&bianshu);

	for(i=1; i<=bianshu; i++)
		for(j=1; j<=bianshu; j++)
		{
			if(i==j) 
				ditu[i][j] = 0;
			else
				ditu[i][j] = 9999;

		}

	for(i=1;i<=bianshu;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		ditu[a][b] = c;
	}

	for(k = 1; k<=dianshu; k++)
		for(i=1; i<=dianshu; i++)
			for(j=1; j<=dianshu;j++)
				if(ditu[i][j] > ditu[i][k] + ditu[k][j])
					ditu[i][j] = ditu[i][k] + ditu[k][j];

	for(i=1; i <= dianshu; i++)
	{
		for(j=1; j <= dianshu; j++)
		{
			printf("%10d",ditu[i][j]);
		}
		printf("\n");

	}

	system("pause");
}
/*结束时间： 2016-09-06 21:44:32
  存在问题：
  核心功能：floyd 算法的语句少 求任意两点之间的最短路径 关键是要把临界条件算好 都是点的数量 从下标1开始
  防止内存越界 导致相邻数据被替代
*/