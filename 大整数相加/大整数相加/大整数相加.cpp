/*��ʼʱ�䣺 2016-08-14 20:11:22
ʵ�ֹ��ܣ�
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

	while(st<ed)//ʹ�ö�̬�ж�������ʱ�� Ҫ���жϵı����Ĵ�С�ı����д���� ��С�ڳ��� ��ʾ�����Խ��н���
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
	
	reverse(num1);//��ת
	reverse(num2);


	int len = strlen(num1) > strlen(num2)?strlen(num1):strlen(num2);//������ַ��� �������Ϊѭ������

	if(strlen(num1)>strlen(num2)) //�ѽ϶̵�һ���ַ����Ľ�β��Ϊ '0' ��һ��
		num2[strlen(num2)]='0';
	else
		num1[strlen(num1)]='0';


	for(i=0; i<len; i++)//��ת�������� ������ִ�в��� �͹�ʽһ������
	{
		result[i]=num1[i]+num2[i] + Add - '0' - '0';
		Add=result[i]/10;
		result[i]=result[i]%10;
		result[i]=result[i]+'0';//��ԭ���ַ�����ʽ

	}

	if(Add==1)//��Ϊ���i��len�� ����ֱ��result[i]����
	{
		result[i]='1';
		result[i+1]='\0';

	}
	else
		result[i]='\0';

	reverse(result);//��ת һ%s����ʽ��ӡ����
	
	printf("%s\n",result);

731428955910363076048537974792133456430022
731428955910363076048538024792133456430022

    system("pause");
    return 0;
}