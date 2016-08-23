/*开始时间： 2016-07-18 16:18:12
实现功能：删除中间 保留两端
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
	char shuru[150]={0};
	int i=0,j,k;

	scanf("%s",shuru);

	while(shuru[i]=='*')
		i++;
	for(j=strlen(shuru)-1;shuru[j]=='*';j--)
		;

	for(k=i;k<=j;k++)
		if(shuru[k]=='*')
			shuru[k]='#';

	for(i=0;i<strlen(shuru);i++)
		if(shuru[i]=='#')
			continue;
		else
		printf("%c",shuru[i]);

	printf("\n");

    system("pause");
    return 0;
}
/*结束时间： 2016-07-18 16:30:57
  存在问题：
  核心功能： 使用头尾两个指针 指向非*号的字符
*/