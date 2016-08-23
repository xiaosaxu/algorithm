/*开始时间： 2016-08-13 13:21:14
实现功能：
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int zhuanhua(char data)
{
	if(data<='9'&&data>='0')
		return data-'0';
	if(data<='F' && data>='A')
		return data-'A'+10;
}

int main(void)
{
	
	char shuru[100]={0};
	int jieguo=0,j=0;
	int temp;

	gets(shuru);

	for(int i=strlen(shuru)-1; i>1; i--)
	{
		temp=zhuanhua(shuru[i]);
		jieguo=jieguo+temp * pow((double)16,j++);
	}

	printf("%d\n", jieguo);

    system("pause");
    return 0;
}
/*结束时间： 2016-08-13 13:33:22
  存在问题：
  核心功能：注意16进制 A到F之间数值的转化
*/