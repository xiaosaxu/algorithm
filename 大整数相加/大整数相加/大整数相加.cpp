/*开始时间： 2016-08-14 20:11:22
实现功能：
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

void reverse(char * shuru)
{
	int st=0;
	int ed=strlen(shuru)-1;
	char temp;

	while(st<ed)//使用动态判断条件的时候 要把判断的变量的大小改变过程写出来 当小于成立 表示还可以进行交换
	{
		temp=shuru[st];
		shuru[st]=shuru[ed];
		shuru[ed]=temp;
		
		st++;
		ed--;
	}
}

int main(void)
{
	char num1[10000]={0};
	char num2[10000]={0};
	char result[10000]={0};
	int i,j;
	int Add=0;

	for(i=0; i<10000; i++)
	{
		num1[i]='0';
		num2[i]='0';
	}

	scanf("%s",num1);
	scanf("%s",num2);
	
	reverse(num1);//翻转
	reverse(num2);


	int len = strlen(num1) > strlen(num2)?strlen(num1):strlen(num2);//求最长的字符串 以最长的作为循环次数

	if(strlen(num1)>strlen(num2)) //把较短的一个字符串的结尾变为 '0' 归一化
		num2[strlen(num2)]='0';
	else
		num1[strlen(num1)]='0';


	for(i=0; i<len; i++)//翻转后进行相加 真正的执行部分 和公式一致起来
	{
		result[i]=num1[i]+num2[i] + Add - '0' - '0';
		Add=result[i]/10;
		result[i]=result[i]%10;
		result[i]=result[i]+'0';//还原成字符的新式

	}

	if(Add==1)//因为最后i是len了 所以直接result[i]即可
	{
		result[i]='1';
		result[i+1]='\0';

	}
	else
		result[i]='\0';

	reverse(result);//翻转 一%s的新式打印出来
	
	printf("%s\n",result);

731428955910363076048537974792133456430022
731428955910363076048538024792133456430022

    system("pause");
    return 0;
}