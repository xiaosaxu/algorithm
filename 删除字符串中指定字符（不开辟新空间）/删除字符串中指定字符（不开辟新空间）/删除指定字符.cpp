/*开始时间： 2016-07-12 16:22:11
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

void deletechar(char* shuru,char shanchu)
{
	int i=0,j=0;
	while(shuru[i])
	{
		if(shuru[i]!=shanchu)//不等于为想提取的数据
			shuru[j++]=shuru[i];
		i++;
	}
	shuru[j]='\0';//这个非常重要 因为在while()循环里面 到最后一个\0字符的时候是退出循环的 因此会丢失掉字符串的结束标志 之后打印会一直打印到原字符串的结束地方
}
int main(void)
{
    
	char shuru1[100]={0},shanchu;
	char *shuru=shuru1;

	gets(shuru);

	scanf("%c",&shanchu);

	deletechar(shuru,shanchu);

	printf("%s",shuru);

    system("pause");
    return 0;
}

/*结束时间： 2016-07-12 16:36:23
  存在问题：
  核心功能：j是一个只受有效字符影响的自加变量  而i是遍历所有的 有效位则会挨次序存放 最后一定要记得加上'\n' 字符串结束标志
*/