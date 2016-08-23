/*开始时间： 2016-07-11 14:21:25
实现功能：插入排序与希尔排序
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<time.h>
using namespace std;

int main(void)
{
	int i,j,temp,charu[100]={0},xier[100]={0};
    srand((unsigned int)time(NULL));

	for(i=0;i<100;i++)
		xier[i]=charu[i]=rand()%20;
	for(i=0;i<100;i++)
		printf("%d ",charu[i]);
	printf("\n");


	//插入排序部分
	for(i=1;i<100;i++)//因为第一个元素只有一个元素 当作已经排号序 所以待插入的元素从第二个开始 到最后一个
	{
	temp=charu[i];							//把待插入的元素备份 以为移动过程会把该元素覆盖  往后移动的过程 最后留出该元素的位置 插进去
	for(j=i-1;j>=0&&temp<charu[j];--j)		//从已经排号序的后一个元素往前查找 这是一个移动的过程 移动好之后在插入
		charu[j+1]=charu[j];				//注意这里是把前面的元素往后移动 所以是j赋值给j+1

	charu[j+1]=temp;//果然是j+1 因为是先操作 在对变量执行自减 操作完往前移动了 所以在返回
	}
	//结束
	for(i=0;i<100;i++)
		printf("%d ",charu[i]);
		printf("\n");
			printf("\n");

	//希尔排序部分 希尔排序是直接插入排序的改进版 采用了类似于分治的思想 不断的缩小间隔
		for(i=0;i<100;i++)
		printf("%d ",xier[i]);
					printf("\n");
	int d=100/2,x;
	while(d>=1)
	{
		for(i=d;i<100;i++)//第一次划分的全部结束
		{
			x=xier[i];
			j=i-d;
			while(j>=0&&xier[j]>x)
			{
				xier[j+d]=xier[j];
				j=j-d;
			}
			xier[j+d]=x;
		}
		d/=2;//下一次分组

	}


	
		for(i=0;i<100;i++)
		printf("%d ",xier[i]);



    system("pause");
    return 0;
}

/*结束时间： 2016-07-11 15:42:03
  存在问题：需要自己手写这些代码，在草稿纸上实现一遍
  核心功能：插入排序的核心功能是把已排序的下一个元素作为待插入元素，循环 往前 比较 已经排号顺序的部分   如果符合条件（比如要从小到达排序 则后面元素（哨兵）比已排序元素小）则把元素往后移动
*/