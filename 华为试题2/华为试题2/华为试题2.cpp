/*开始时间： 2016-07-18 20:10:20
实现功能：
输入:	
输入有多组，每组输入第一行是一个整数n（1<=n<=1000000），接下来n行的每行包括三个整数l,w和h（1 <= w,l,h <= 100），表示积木的长宽高，﻿整数用空格隔开。
输出:	
对于每组输入，输出按规则最多能垒几个积木。
样例输入:	
3
5 2 1
4 2 1
3 3 1
3
1 5 1
5 1 1
2 2 2
样例输出:	
2
1
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct shuju
{
	int l;
	int w;
	int h;
}JiMu;

int cmp(JiMu s1,JiMu s2)
{
	if(s1.l>s2.l)
		return 1;
	else
		return 0;
}

JiMu jimu[10000]={0}; 

int main(void)
{
	int n,i,k,j=0;
    while (scanf ("%d", &n) != EOF)
	{  
        memset (jimu, 0, sizeof(jimu));  
		for (i=0; i<n; i++)
            scanf ("%d%d%d", &jimu[i].l, &jimu[i].w, &jimu[i].h);  
        
		sort(jimu,jimu+n,cmp);//先进行一次排序


		for(i=0;i<n;i++)
		{
			for(k=i;k<n;k++)
			{
				if(jimu[i].w<jimu[k].w)//筛选宽
					jimu[k].w=0;
				if(jimu[i].h<jimu[k].h)//筛选高
					jimu[k].h=0;

			}		
		}
		j=0;
		for(i=0;i<n;i++)
		{
			if(jimu[i].l!=0&&jimu[i].w!=0&&jimu[i].h!=0)//统计
				j++;
		}

		printf("%d\n",j);

	}

    system("pause");
    return 0;
}

/*结束时间： 2016-07-18 20:37:25
  存在问题：
  核心功能： 使用循环读入 while (scanf ("%d", &n) != EOF) 根据长宽高从大到小 三个条件逐步筛选
*/