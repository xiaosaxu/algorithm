/*
����ַ�������������ַ��������ĳ��ȡ�
��������ַ���Ϊ�գ���ֻ���0
�� input: dadfsaf  output:0

��������	abcd12345ed125ss123058789
�������	123058789,9


�ӿ�˵��
����ԭ�ͣ�
   unsignedint Continumax(char** pOutputstr,  char* intputstr)
���������
   char* intputstr  �����ַ�����
���������
   char** pOutputstr: ����������ִ����������������ִ��ĳ���Ϊ0��Ӧ�÷��ؿ��ַ�������������ַ����ǿգ�ҲӦ�÷��ؿ��ַ�����  
����ֵ��
  ����������ִ��ĳ���



*/



//�õ�����OJ������һ�����԰������ǲ�������֪���ǲ��ǿ��ַ�����ʶ������
//�Ժ����������жϵ�ʱ��Ҫע��һ��


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<system.h>

struct jilu
{
int statrt;
int end;
int length;
};
int main()
{
char * shuru;
char ShuRu[100];
int i,j=0,len=0,max=0,end=-1;
struct jilu JiLu[100]={0,0,0};

shuru=ShuRu;
//scanf("%s",ShuRu);
gets(ShuRu);
if(strlen(shuru)==0)
{
	printf("\0");return 0;}

for(i=0;i<strlen(ShuRu);i++)
	if(ShuRu[i]<='9'&&ShuRu[i]>='0')
		{
			len++;
			if(len>max)
				max=len;
				end=i;//������Լ�¼������ִ��Ľ�β
		}
	else 
		len=0;


/*
for(i=0;i<strlen(ShuRu);i++)
 if(ShuRu[i]<='9'&&ShuRu[i]>='0'&&ShuRu[i-1+max]<='9'&&ShuRu[i-1+max]>='0'&&)
	 for(j=i;j<i+max;j++)
	 printf("%c",ShuRu[j]);
*/
if(end!=-1)
{
	for(i=end-max+1;i<=end;i++)
	printf("%c",ShuRu[i]);
	printf(",%d\n",max);
}
else printf("0\n");


system("pause");

}