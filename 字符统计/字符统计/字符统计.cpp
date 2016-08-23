/*开始时间： 2016-08-14 09:53:26
实现功能：输入一个字符串，对字符中的各个英文字符，数字，空格进行统计（可反复调用）
    按照统计个数由多到少输出统计结果，如果统计的个数相同，则按照ASII码由小到大排序输出
    清空目前的统计结果，重新统计
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int fuhe(char shuru)
{
	if((shuru<='Z'&&shuru>='A')||(shuru<='z'&&shuru>='a')||(shuru<='9'&&shuru>='0')||shuru==' ')
		return 1;
	else
		return 0;
}

int comp(int a,int b)
{
	return a>b;
}
int main(void)
{
    char shuru1[10000];
	char *shuru=shuru1;
    int	book[300]={0};
	int book2[300]={0};
	int i=0,j=0;

	gets(shuru);

	if(strlen(shuru)==0)
		return 0;

	for(i=0; i<strlen(shuru); i++)
	{
		if(fuhe(shuru[i]))
		{
			book[shuru[i]]++;
			book2[shuru[i]]++;
		}
	}

	sort(book,book+300,comp);


	for(i=0; i<300&&book[i]>0; i++)
	{
		for(j=0;j<300; j++)
			if(book[i]==book2[j])
			{
				printf("%c",j);
				book2[j]=0;
				break;
			}
	}
	printf("\n");
    system("pause");
    return 0;
}
/*结束时间： 2016-08-14 10:21:46
  存在问题：
  核心功能： 使用两个数组保存 一个保存原始序列和出现的关系 一个进行排序 （sort默认从小到大排序） 因为数组序号递增的 满足题意 相同输出小的 
				对每一个次数 在另一个数组中进行遍历（从小到大）（如果相同是输出大的 则从大到小进行遍历） 需要遍历255的平方 输出一个则置零 防止下次找到
*/