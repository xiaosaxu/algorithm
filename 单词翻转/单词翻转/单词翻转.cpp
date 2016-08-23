/*开始时间： 2016-07-11 21:03:09
实现功能：单词翻转
通过输入英文句子，将每个单词反过来，标点符号顺序不变。非26个字母且非标点符号的情况即可标识单词结束。
标点符号包括,.!?

样例输入	Hello, I need an apple.
样例输出	olleH, I deen na elppa.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

void swap(char shuru[],int st,int ed)
{
	char temp;
	while(st<ed)
	{
		//判断是有特殊符号
		while(shuru[st]==','||shuru[st]=='.'||shuru[st]=='!'||shuru[st]=='?'||shuru[st]==' ')//采用这种机制也能实现保留符号位置不变的翻转
			st++;
		while(shuru[ed]==','||shuru[ed]=='.'||shuru[ed]=='!'||shuru[ed]=='?'||shuru[ed]==' ')
			ed--;
		if(st<ed)//防止单词只有一个单词 不需要交换
		{
		temp=shuru[st];
		shuru[st]=shuru[ed];
		shuru[ed]=temp;

		st++;
		ed--;
		}
	}
}

int main(void)
{
	char shuru1[100]={0};
    char *shuru=shuru1;
	int i=0,j=0,k=0,kge[100]={0};

	gets(shuru);

	
	j=1;//第一个元素位置
	for(i=0;i<strlen(shuru);i++)
		if(shuru[i]==' ')
			kge[j++]=i;
	
	kge[j]=strlen(shuru)-1;//最后一个元素位置 这里使用了减一

	for(k=1;k<=j;k++)//对每个单词进行交换
		swap(shuru,kge[k-1],kge[k]);

	for(i=0;i<strlen(shuru);i++)
		printf("%c",shuru[i]);
	printf("\n");

    system("pause");
    return 0;
}
/*结束时间： 2016-07-11 21:47:31
  存在问题：strlen()求的结果比实际值大1？ 导致字符串结束符被换到最后一个单词前面 使得最后一个单词被截断 为什么

      解释：strlen()返回的是实际字符串中字符的个数 如果一个字符串 "I" 仅由I这一个字符组成那么strlen()返回1，当用1去访问该字符串的数组的时候就会导致访问到字符串结尾标志 
	        正确的访问应该是 shuru[0] 因此我们在循环里面使用的时候是 <strlen(shuru),而没有等于！ 



  核心功能：使用头尾两个指针 进行交换 并且移位
  while(shuru[st]==','||shuru[st]=='.'||shuru[st]=='!'||shuru[st]=='?'||shuru[st]==' ')
			st++;
			原来使用if导致只判别一次 当有连续的两个符号 比如, （逗号个空格）在一起不能准确的移位

			使用kge[]数组存放每个单词的结束位置
*/