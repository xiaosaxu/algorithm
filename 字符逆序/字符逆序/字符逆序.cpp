/*开始时间： 2016-08-14 10:25:48
实现功能：将一个字符串str的内容颠倒过来，并输出。str的长度不超过100个字符。 如：输入“I am a student”，输出“tneduts a ma I”。
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std; 

int main(void)
{
    char shuru1[1000];
	char *shuru=shuru1;
	int pt=0,pw=0;
	char temp;

	gets(shuru);

	for(pt=0, pw=strlen(shuru)-1;pt<pw;)
	{
		temp=shuru[pt];
		shuru[pt]=shuru[pw];
		shuru[pw]=temp; 
		pt++,pw--;
	}

	printf("%s\n", shuru);

    system("pause");
    return 0;
}
/*结束时间： 2016-08-14 10:38:22
  存在问题：
  核心功能：
*/