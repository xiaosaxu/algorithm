/*开始时间： 2016-08-15 14:32:18
实现功能：实际上DFS生成全排列可以由函数 sort（）  next_permutation() 代替
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

int visit[100] = {0};
int pailie[100] = {0};
int fanwei = 0;

char shuru[30] = {0};
char jieguo[30] = {0};
int book[20] = {0};
int len=0;


void DFS(int deepth)
{
	if(deepth > fanwei)
	{
		for(int i=0; i<= fanwei ;i++)
		{
			printf("%d ",pailie[i]);	
		}
		printf("\n");
	}
	else
	{
		for(int i=0; i <= fanwei; i++)
			if(visit[i] == 0)
			{
				visit[i]=1;
				pailie[deepth]=i;
				DFS(deepth+1);
				visit[i]=0;
			}
	}
}

void DFS2(int deepth)
{
	if(deepth>=len)
	{
			printf("%s\n", jieguo);
	}
	else
	{
		for(int i=0; i<len; i++)//从备用库里面搜索能使用的
			if(book[i] == 0)
			{
				book[i] = 1;//实际上是要对下标进行 定位 表明该位置的元素已被使用

				jieguo[deepth] = shuru[i];
				DFS2(deepth+1);

				book[i] = 0;
			}
	}
}

int main(void)
{

int runflag=0;
printf("输入1运行数字的全排列 输入格式 整数N 输出（0—N）的全排列\n输入2运行字符串的全排列 输入一行字符串 输出该字符串的全排列\n");
scanf("%d",&runflag);

if(runflag==1)
{
    scanf("%d",&fanwei);
	DFS(0);
}

if(runflag==2)
{
	gets(shuru);
	len=strlen(shuru);
	DFS2(0);
}

    system("pause");
    return 0;
}
/*结束时间： 2016-08-15 15:34:23
  存在问题：
  核心功能：结果数组 book数组 递归结束的边界条件判断 递归之后要book回该数字
*/
