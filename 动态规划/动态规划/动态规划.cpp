/*开始时间： 2016-08-14 14:11:49
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int mymax(int a,int b )
{
	return (a>b?a:b); //这里使用了自定义函数 求最大值
}

int main(void)
{
	
	int money=0;
	int num=0;
	int k=0;

	int goodsinfo[70][3]={0};

	int Value[70][3500]={0};//定义的数组大小要比实际的大

	int i=0,j=0;

	scanf("%d %d", &money,&num);
	money/=10;//所有的钱都要除以10

	for(i=1; i<=num; i++)
	{
		scanf("%d %d %d",&goodsinfo[i][0],&goodsinfo[i][1],&goodsinfo[i][2]);//价格 重要度
		//因为在动态规划的循环中的下标从1开始的 因此 存储物品信息的数组的下标也要从1开始 而总数不变 所以是小于等于num。
	}
	for(i=1; i<=num; i++)
	{
		goodsinfo[i][0]/=10;//统一全部除以10
	}

	for(i=1; i<=money; i++)//钱 有多少钱就要循环多少次 实际使能取到meoney值的 所以之前定义的数组的的大小要比实际的大一些
		for(j=1; j<=num; j++)//货物数量 有多少货物也要循环多少次
		{
			if(goodsinfo[j][2]==0)//说明是主件
			{
				if(i>=goodsinfo[j][0])
				{
					Value[j][i]=mymax(Value[j-1][i],Value[j-1][i-goodsinfo[j][0]]+goodsinfo[j][0]*goodsinfo[j][1]);//分为拿 或者 不拿
				}
				else
				{
					Value[j][i]=Value[j-1][i];//表示放不进去 保留上一个值
				}
			}

			else//从件
			{
				k=goodsinfo[j][2];//主件的编号

				if(i>=goodsinfo[j][0]+goodsinfo[k][0])
				{
					Value[j][i]=mymax(Value[j-1][i],Value[j-1][i-goodsinfo[j][0]-goodsinfo[k][0]]+goodsinfo[j][0]*goodsinfo[j][1]+goodsinfo[k][0]*goodsinfo[k][1]);//分为拿 或者 不拿
				}
				else
				{
					Value[j][i]=Value[j-1][i];//表示放不进去 保留上一个值
				}
			}
		}

		printf("%d\n", Value[num][money]*10);//之前除掉的要记得成回来
	

    system("pause");
    return 0;
}
/*结束时间： 2016-08-14 14:54:26
  存在问题：
  核心功能： 只和当前列有关 其他列无关 第一次总是把第一个能放进去的值放进去 注意循环的小标系数 从1开始
			动态规划除了思想上要理解 数据结构的表达 程序的结构都是需要考虑的
*/