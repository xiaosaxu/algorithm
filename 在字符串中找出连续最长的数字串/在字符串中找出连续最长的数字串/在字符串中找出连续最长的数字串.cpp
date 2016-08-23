/*开始时间： 2016-07-18 08:58:49
实现功能：在字符串中找出连续最长的数字串

输入	
输入一个字符串。
输出	
输出字符串中最长的数字字符串和它的长度。
如果数字字符串为空，则只输出0
如 input: dadfsaf  output:0
样例输入	abcd12345ed125ss123058789
样例输出	123058789,9

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

void FindNumList(char * shuru)
{
	int i,k,st,max=0;
	for(i=0;i<strlen(shuru);i++)
	{
		for(k=0;shuru[i+k]!='\0'&&(shuru[i+k]<='9'&&shuru[i+k]>='0');k++)
			;
		if(k>max)
		{
		max=k;
		st=i;
		}
	}
	for(i=0;i<max;i++)
		printf("%c",shuru[st+i]);
	if(max>0)
	printf(",");
	printf("%d\n",max);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    
	char shuru[100];
	gets(shuru);
	

	FindNumList(shuru);

    system("pause");
    return 0;
}

/*结束时间： 2016-07-18 09:16:24
  存在问题：
  核心功能：
*/