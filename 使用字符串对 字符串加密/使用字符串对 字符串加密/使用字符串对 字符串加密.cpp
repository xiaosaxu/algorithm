// ʹ���ַ����� �ַ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
��һ�ּ��ɿ��Զ����ݽ��м��ܣ���ʹ��һ��������Ϊ�����ܳס����������Ĺ���ԭ�����ȣ�ѡ��һ��������Ϊ�ܳף���TRAILBLAZERS����������а������ظ�����ĸ��ֻ������1�������༸�����������ڣ��޸Ĺ����Ǹ�����������ĸ������棬������ʾ��
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
T R A I L B Z E S C D F G H J K M N O P Q U V W X Y
������������ĸ����ʣ�����ĸ����������ڶ���Ϣ���м���ʱ����Ϣ�е�ÿ����ĸ���̶��ڶ������У������������еĶ�Ӧ��ĸһһȡ��ԭ�ĵ���ĸ(��ĸ�ַ��Ĵ�Сд״̬Ӧ�ñ���)����ˣ�ʹ������ܳף�Attack AT DAWN(����ʱ����)�ͻᱻ����ΪTpptad TP ITVH��
��ʵ�������ӿڣ�ͨ��ָ�����ܳ׺����ĵõ����ġ�
��ϸ������
�ӿ�˵��
ԭ�ͣ�
voidencrypt(char * key,char * data,char * encrypt);
���������
    char * key���ܳ�
    char * data������
���������
    char * encrypt������
����ֵ��
        void


*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{

	char a[200]={0},b[200]={0},book[200]={0};
	char key[20]={0},data[20]={0};
	int i=0,j=0;

	for(i='A';i<='Z';i++)//��ʼ��a
		a[i]=i;


	scanf("%s",key);
	scanf("%s",data);



	for(i=0;i<strlen(key);i++)
	{
		if(key[i]>'Z')//Сдת��д
			key[i]-=('a'-'A');
	}


	for(i=0;i<strlen(key);i++)
		if(book[key[i]]==0)
		{
			b[j++]=key[i];
			book[key[i]]=1;
		}
	b[j]='\0';//��һ�����


	for(i=strlen(b)-1;i<26;i++)//һ��26��Ӣ����ĸ
	{
		for(j='A';j<='Z';j++)
		if(book[key[j]]==0)
		{
			book[key[j]]=1;
			b[i]=j;
			break;//��ǰԪ�ظ�ֵ��� �˳���ǰ��ѭ�� ������һ��Ԫ���ж�
		}
	}
	
	printf("%s",b);

	printf("%s",data);


	system("pause");
	return 0;
}

