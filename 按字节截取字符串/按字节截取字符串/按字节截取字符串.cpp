/*开始时间： 2016-08-01 23:19:40
实现功能：
编写一个截取字符串的函数，输入为一个字符串和字节数，输出为按字节截取的字符串。但是要保证汉字不被截半个，
如"我ABC"4，应该截为"我AB"，输入"我ABC汉DEF"6，应该输出为"我ABC"而不是"我ABC+汉的半个"。 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
	char shuru[100] = {0};
	int num = 0,i,sum = 0;

	scanf("%s %d", shuru, &num);
/*
	for(i=0;i<sizeof(shuru);i++)
		printf("%c ",shuru[i]);//打印assic可知 汉字的字符assic小于0 用于判断

	printf("\n");
*/
	for (i=0; i<num; i++)
		if (shuru[i] < 0)
			sum++;

	if(sum%2 == 0) 
		shuru[num] = '\0';
	else
		shuru[num-1] = '\0';

	printf("%s\n", shuru);


    system("pause");
    return 0;
}
/*结束时间： 2016-08-01 23:40:00
  存在问题：
  核心功能：当输出的位置在两个汉字中间时候，导致前后的判断都是小于0的 因此不能简单的以规定字符数的前后判断 
			本程序采用打印规定字符数之前对包含的汉字字符进行统计（一个汉字两个字符（assic码小于0））若为偶数则直接打印 若为奇数则往前退一个
			采用打印字符串的形式整体打印
*/