/*��ʼʱ�䣺 2016-07-10 22:13:29
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

void Ten2N(int a,int N)
{
	int result=0,temp,i=0,j=a;
	char aa[20]={0};
	while(a>0)
	{
		temp=a%N;

		if(temp<10)
		aa[i++]=temp+'0';
		else
		aa[i++]='a'+temp-10;

		a/=N;
	}
	printf("10������%dת����%d������Ϊ",j,N);

	for(j=i-1;j>=0;j--)
	printf("%c",aa[j]);

	printf("\n");


}

void N2Ten(int N,int a)//���Ӧ�ÿ��ǳ��ַ�����  ���ԸĽ��ĵط�
{
	int temp,i=0,sum=0,j=a;
	while(a>0)
	{
		temp=a%10;
		sum=sum+temp*pow((double)N,(double)i);
		i++;
		a/=10;
	}
	printf("%d������%dת����10������Ϊ %d\n",N,j,sum);
}

int main(void)
{
 //10����ת����N����   

	Ten2N(2012,16);

	N2Ten(5,213);

	system("pause");
    
	return 0;
}

/*��ʼʱ�䣺 2016-07-10 23:10:00
ʵ�ֹ��ܣ�
*/


/*��ʼʱ�䣺 2016-07-10 23:13:11
ʵ�ֹ��ܣ�

���Ĵ��룺
		sum=sum+temp*pow((double)N,(double)i);




	while(a>0)
	{
		temp=a%N;

		if(temp<10)
		aa[i++]=temp+'0';
		else
		aa[i++]='a'+temp-10;

		a/=N;
	}


*/