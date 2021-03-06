/*开始时间： 2016-07-15 09:26:57
实现功能：

描述	
•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
知识点	字符串
运行时间限制	10M
内存限制	128
输入	
连续输入字符串(输入2次,每个字符串长度小于100)
输出	
输出到长度为8的新字符串数组
样例输入	abc 123456789
样例输出	abc00000 12345678 90000000
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

void FenGe(char *shuru)
{
	int i,j=0,k;
	int total=0;
	if(strlen(shuru)%8==0)
		total=strlen(shuru);
	else
		total=((int)strlen(shuru)/8+1)*8;

	for(i=0;i<total;i++)
	{
		if(i<strlen(shuru))
			printf("%c",shuru[i]);
		else
			printf("%c",'0');

		j++;
		if(j%8==0)
			printf("\n");

	}
}

int main(void)
{
	char shuru[200]={0};
	char shuru1[200]={0};
	scanf("%s",shuru);
	scanf("%s",shuru1);

	FenGe(shuru);
	FenGe(shuru1);

    system("pause");
    return 0;
}

/*结束时间： 2016-07-15 10:06:09
  存在问题：在对total进行计数的时候要注意对8的倍数和不是8的倍数情况的分别讨论 在循环控制空格输出的时候原来使用的i i从0开始导致不准 后采用使用变量j单独统计计数 控制换行输出
  核心功能：
*/