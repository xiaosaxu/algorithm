/*开始时间： 2016-08-13 11:19:22
实现功能：
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std; 

void fenge(char * shuru)
{
	int i,j,k;
	if(strlen(shuru)==0)
		return;

	for(i=strlen(shuru)-1;i>=0; i--)
		shuru[i+1]=shuru[i];//所有元素往后面移动一位

	for(i=1;i<(strlen(shuru)-1)/8*8+1; i++)//第一部分
	{
		printf("%c",shuru[i]);
		if(i%8==0)
			printf("\n");
	}

	for(i;i<strlen(shuru); i++)//第二部分
	{
		printf("%c",shuru[i]);
	}
	if(((strlen(shuru)-1))%8==0)
			;
	else
	{
		for(i;i< (strlen(shuru)-1)/8*8+1+8; i++)//第三部分
			printf("0");

		printf("\n");
	}

}

int main(void)
{
	char shuru[1000]={0};
	char shuru2[1000]={0};

	gets(shuru);
	gets(shuru2);

	fenge(shuru);
	fenge(shuru2);
		


    system("pause");
    return 0;
}

/*结束时间： 2016-08-13 13:13:21
  存在问题： 1.0%N==0 加上 从0开始不行 整体数组往后面移动一位 2.当时8的倍数的时候输出一行0 对是8的倍数的情况单独判断了
  核心功能： 三块分别求解

  三块功能分别是 1打印开始到最后一个8的倍数 2.最后一行打印剩下的数 3.不足的数补零
*/