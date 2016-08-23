#include<stdio.h>//gets printf
#include<string.h>//strlen
#include<stdlib.h>//system（“pause”）
int main(void)//改进 避免使用void main()
{
char shuru[200];
char * a;//可以求长度的字符串输入

int len=0,i,index=-1;
a=shuru;

gets(a);//原来使用scanf不能得到空格后面的字符串！

len=strlen(a);
if(len==0) return 0;//输入为空判断
if(len>128) return 0;//大于设定长度

for(i=len-1;i>=0;i--)//从后往前寻找第一个出现的空格，作为最后一个单词
{
if(shuru[i]==' ')
{index=i;break;}//找到

}
if(index==-1)//未找到空格
printf("%d\n",len);
else
printf("%d\n",len-1-index);

/*
printf("hello world %s \n",shuru);
printf("hello world %s \n",a);
printf("hello world %d \n",len);
system("pause");
*/
}