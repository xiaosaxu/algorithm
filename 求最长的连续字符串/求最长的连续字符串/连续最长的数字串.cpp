/*
输出字符串中最长的数字字符串和它的长度。
如果数字字符串为空，则只输出0
如 input: dadfsaf  output:0

样例输入	abcd12345ed125ss123058789
样例输出	123058789,9


接口说明
函数原型：
   unsignedint Continumax(char** pOutputstr,  char* intputstr)
输入参数：
   char* intputstr  输入字符串；
输出参数：
   char** pOutputstr: 连续最长的数字串，如果连续最长的数字串的长度为0，应该返回空字符串；如果输入字符串是空，也应该返回空字符串；  
返回值：
  连续最长的数字串的长度



*/



//该道题在OJ里面有一个测试案例总是不过，不知道是不是空字符串的识别问题
//以后遇到输入判断的时候要注意一下


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<system.h>

struct jilu
{
int statrt;
int end;
int length;
};
int main()
{
char * shuru;
char ShuRu[100];
int i,j=0,len=0,max=0,end=-1;
struct jilu JiLu[100]={0,0,0};

shuru=ShuRu;
//scanf("%s",ShuRu);
gets(ShuRu);
if(strlen(shuru)==0)
{
	printf("\0");return 0;}

for(i=0;i<strlen(ShuRu);i++)
	if(ShuRu[i]<='9'&&ShuRu[i]>='0')
		{
			len++;
			if(len>max)
				max=len;
				end=i;//这里可以记录最长的数字串的结尾
		}
	else 
		len=0;


/*
for(i=0;i<strlen(ShuRu);i++)
 if(ShuRu[i]<='9'&&ShuRu[i]>='0'&&ShuRu[i-1+max]<='9'&&ShuRu[i-1+max]>='0'&&)
	 for(j=i;j<i+max;j++)
	 printf("%c",ShuRu[j]);
*/
if(end!=-1)
{
	for(i=end-max+1;i<=end;i++)
	printf("%c",ShuRu[i]);
	printf(",%d\n",max);
}
else printf("0\n");


system("pause");

}