// c++ sort()函数的使用.cpp : 定义控制台应用程序的入口点。
//

#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int comp(int a,int b)
{
	return a<b;
}


typedef struct paixu_tag
{
	int a;
	int b;
}paixu_type;

int comp2(struct paixu_tag &aa,struct paixu_tag &bb)
{
	return aa.a > bb.a ;
}

//可以使用 struct paixu_tag aa;  或者 paixu_type 命名结构体变量

int main(void)
{
	paixu_type stt[100]={0};
	
	int shuru[100]={0},i,j;
	for(i=0;i<10;i++)
		scanf("%d",&shuru[i]);//注意 如果是输入字符 %c scanf函数会把 空格 回车 等字符输入进去

	stable_sort(shuru,shuru+10,comp);//整形数组比较函数

		for(i=0;i<10;i++)
		printf("%d ",shuru[i]);
		printf("\n ");

		for(i=0;i<100;i++)
			stt[i].a=i;//结构体初始化

		sort(stt,stt+100,comp2);//结构体排序 还是数组 地址的 偏移

			for(i=0;i<100;i++)
			printf("%d ",stt[i].a);



		system("pause");

	return 0;
}

