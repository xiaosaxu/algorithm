// 删除字符串中出现次数最少的字符.cpp : 定义控制台应用程序的入口点。
//
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

int main(void)
{

	char shuru[30]={0};
	int book[255]={0},book2[255]={0},i,j;

	scanf("%s",shuru);

	for(i=0;i<strlen(shuru);i++)
	{
		book[shuru[i]]++;
		book2[shuru[i]]++;//留一个进行备份 因为book1会在排序后顺序改变
	}

	sort(book,book+255);//这里调用sort函数 减少了编写程序时间

	for(i=0;i<255;i++)
	{
	//printf("%d ",book[i]);
	if(book[i]>0)//找到频率最小的数字
		{
			j=book[i];
			break;
		}
	}

	for(i=0;i<strlen(shuru);i++)
	{
		if(book2[shuru[i]]>j)//频率大于才会输出 否则不输出
			printf("%c",shuru[i]);
	}
    printf("\n");
//	system("pause");

	return 0;
}

