/*开始时间： 2016-07-17 09:18:13
实现功能：最长公共子串 不区分大小写
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int FindLen(char *shuru1,char * shuru2)
{
	char *s1,s2;
	int i,j,k,max=0;
	for(i=0;shuru1[i];i++)
		for(j=0;shuru2[j];j++)
		{
			for(k=0;(shuru1[i+k]==shuru2[j+k])&&(shuru1[i+k]||shuru2[j+k]);k++)
			{
				;
			}		
			if(k>max)
				max=k;
		}
	return max;//记住 要返回 求出来的最大值
}
void ToUper(char *shuru)
{
	int i=0;
	for(i=0;i<strlen(shuru);i++)
		if(shuru[i]<='z'&&shuru[i]>='a')
			shuru[i]=shuru[i]-('a'-'A');
}
/*
int FindLen(char *shuru1,char * shuru2)
{
	char *s1=shuru1,*s2=shuru2;
	int len=0,max=0;
	for(shuru1;'0'!=*shuru1;shuru1++)
	{
		s1=shuru1;
		s2=shuru2;
		for(s2;'0'!=*s2;s2++)
		{
			
			len=0;
			while(('0'!=*s1)&&('0'!=*s2)&&(*s1==*s2))
			{
				len++;
				s1++;
				s2++;//问题出在这

			}
		if(len>max)
			max=len;
		}

	}	
	return max;

}
*/
int main(void)
{
 
	char shuru1[100]={0};
	char shuru2[100]={0};

	char *shuru3=shuru1;
	char *shuru4=shuru2;

	scanf("%s",shuru3);
	scanf("%s",shuru4);

	ToUper(shuru3);
	ToUper(shuru4);


	printf("%d\n",FindLen(shuru3,shuru4));//换成输入1 2 试试看
    system("pause");
    return 0;
}
/*结束时间： 2016-07-17 10:41:46
  存在问题：
  核心功能：两次嵌套循环 递增 内部匹配使用k变量从0开始依次匹配 最后返回最大值
*/