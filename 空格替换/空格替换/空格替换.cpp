/*开始时间： 2016-08-29 16:48:59
实现功能：把字符串里面的空格替换成%20
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    int i,len;
	char shuru[1000]={0};
	char shuchu[1000]={0};

	gets(shuru);
	len=strlen(shuru);

	if(len==0)
		return 0;



	for(i=0; i<len; i++)
	{
		if(shuru[i]==' ')
			printf("%s","%20");
		else
			printf("%c",shuru[i]);
	}
	
	printf("\n");


	//在原数组上修改 前提 原来的数组足够长 
	//若不能修改原来的数组则需要新建一个临时数组 根据输入的数组的长度动态分配的数组 只要把下面的数组名称改掉就可以了

	int kgenum=0,strnum=0;
	for(i=0; i<len; i++)
	if(shuru[i]==' ')
		kgenum++;

	strnum=len-1+kgenum*2;
	shuru[strnum+1]='\0';
	for(i=len - 1; i>= 0 ;i--)
	{
		if(shuru[i]==' ')
		{
			shuru[strnum--]='0';
			shuru[strnum--]='2';
			shuru[strnum--]='%';

		}
		else
			shuru[strnum--]=shuru[i];

	}

	printf("%s\n",shuru);
		

    system("pause");
    return 0;
}

/*结束时间： 2016-08-29 17:17:58
  存在问题：
  核心功能：使用两个指针 分别指向原数组和新分配的数组的结尾
*/