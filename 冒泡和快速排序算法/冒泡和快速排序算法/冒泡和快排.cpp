/*开始时间： 2016-07-11 10:22:37
实现功能：冒泡排序 交换子函数(形参问题) 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<time.h>
using namespace std;

void jiaohuan(int &a,int &b)//注意把交换封装成函数的时候要特别注意局部变量形参的问题 要加引用 或者指针（对指针的内容进行交换而不是指针！）
{
	int temp;
	temp=b;
	b=a;
	a=temp;
}

int kuaipaiyici(int shuzi[],int L,int H)
{
	int temp=shuzi[L];
	while(L<H)
	{
		while(shuzi[H]>temp&&H>L)
			H--;

		shuzi[L]=shuzi[H];

		while(shuzi[L]<temp&&H>L)
			L++;
		
		shuzi[H]=shuzi[L];
	}
	shuzi[H]=temp;
	return H;
}

void kuaipai_f(int shuzu[],int L,int H)
{
	while(L<H)
	{
		int i=kuaipaiyici(shuzu,L,H);
		kuaipaiyici(shuzu,L,i-1);
		kuaipaiyici(shuzu,i+1,H);
	}
}

int main(void)
{
	int maopao[100]={0},kuaipai[100]={0},i,j,temp;
//生成随机数组部分
    srand((unsigned) time(NULL)); //设置时间种子
	for(i=0;i<100;i++)
	{
		maopao[i]=rand()%50;
		kuaipai[i]=rand()%100;
	}

	for(i=0;i<100;i++)
		printf("%d ",maopao[i]);
	printf("\n");
//冒泡排序部分
	for(i=0;i<100;i++)
		for(j=1;j<100-i;j++)
			if(maopao[j-1]<maopao[j])//交换 的 数组下标变成了j 要注意！
			{
				jiaohuan(maopao[j-1],maopao[j]);
			}
	for(i=0;i<100;i++)
		printf("%d ",maopao[i]);
	printf("\n");

	//	洗牌算法：从前到后每个元素依次和 随机选择一个元素进行交换
	for(i=0;i<100;i++)
	{
		temp=rand()%100;
		jiaohuan(maopao[temp],maopao[i]);

	}
	for(i=0;i<100;i++)
		printf("%d ",maopao[i]);
	printf("\n");

	printf("快排部分\n原数据：\n");
//快速排序部分 快排就是一个不断填坑的过程 取出一个数后面一个符合要求的数填上 最后把本身（哨岗）填上

	for(i=0;i<10;i++)
		printf("%d ",kuaipai[i]);
	printf("\n");
	
	kuaipaiyici(kuaipai,0,9);

	for(i=0;i<10;i++)
		printf("%d ",kuaipai[i]);
	printf("\n");
	


    system("pause");
    return 0;
}
/*结束时间： 2016-07-11 14:03:27
  存在问题：快排一次的功能实现 多次调用功能为实现 一直在死循环 初次怀疑是参数的传递有问题
  核心功能：
  int kuaipaiyici(int shuzi[],int L,int H)
{
	int temp=shuzi[L];
	while(L<H)
	{
		while(shuzi[H]>temp&&H>L)
			H--;

		shuzi[L]=shuzi[H];

		while(shuzi[L]<temp&&H>L)
			L++;
		
		shuzi[H]=shuzi[L];
	}
	shuzi[H]=temp;
	return H;
}
*/