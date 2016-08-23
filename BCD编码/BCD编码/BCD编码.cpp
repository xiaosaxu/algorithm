/*开始时间： 2016-08-07 17:07:57
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(void)
{
	char shuru[50]={0};
	char *shuru1=shuru;
	int i,j,k;
	int temp[8]={0};
	int jisuan=0;

	scanf("%s",shuru1);

	int a=strlen(shuru1);
	if(1==strlen(shuru1)%2)
	{
		for(i=strlen(shuru1); i >=0; i--)
			shuru[i+1]=shuru[i];

		shuru[0]='0';
	}

	for(i=0;i <= strlen(shuru1)-2; i+=2)//边界情况搞清楚
	{
		for(k=0,j = i+1;j>=i; j--)
		{
			int zhuanhua=shuru[j]-'0';
			
			while(zhuanhua)
			{
			temp[k++]=zhuanhua%2;
			zhuanhua=zhuanhua/2;
			}

		k=4;//第二次循环准备

		}

		for(k=0,jisuan=0;k < 8; k++)
		{
			jisuan=jisuan+temp[k]*pow((float)2,k);
			temp[k]=0;//情况数组
		}


		printf("%d",jisuan);


	}



    printf("\n");
//	printf("%s\n",shuru1);
    system("pause");
    return 0;
}

/*结束时间： 2016-08-07 20:03:36
  存在问题：
  核心功能：如果是奇数先在高位补齐 每隔两位转化成2进制数存放在temp[8]数组里面 再把2进制数转化成10进制数 打印出来 在对下一个2位处理
*/