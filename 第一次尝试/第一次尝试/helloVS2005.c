#include<stdio.h>//gets printf
#include<string.h>//strlen
#include<stdlib.h>//system����pause����
int main(void)//�Ľ� ����ʹ��void main()
{
char shuru[200];
char * a;//�����󳤶ȵ��ַ�������

int len=0,i,index=-1;
a=shuru;

gets(a);//ԭ��ʹ��scanf���ܵõ��ո������ַ�����

len=strlen(a);
if(len==0) return 0;//����Ϊ���ж�
if(len>128) return 0;//�����趨����

for(i=len-1;i>=0;i--)//�Ӻ���ǰѰ�ҵ�һ�����ֵĿո���Ϊ���һ������
{
if(shuru[i]==' ')
{index=i;break;}//�ҵ�

}
if(index==-1)//δ�ҵ��ո�
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