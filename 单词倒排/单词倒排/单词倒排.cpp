/*��ʼʱ�䣺 2016-07-16 09:00:46
ʵ�ֹ��ܣ�
����ָ�������������ַ������д���
��ϸ������
������������ַ����ϲ���
�Ժϲ�����ַ�����������Ҫ��Ϊ���±�Ϊ�������ַ����±�Ϊż�����ַ��ֱ��С��������������±���˼���ַ����ַ����е�λ�á�
����ѵ����ַ������в���������ַ�Ϊ��0��������9�����ߡ�A��������F�����ߡ�a��������f������������������16���Ƶ�������BIT����Ĳ�������ת��Ϊ��Ӧ�Ĵ�д�ַ���
���ַ�Ϊ��4����Ϊ0100b����ת��Ϊ0010b��Ҳ����2��ת������ַ�Ϊ��2���� ���ַ�Ϊ��7����Ϊ0111b����ת��Ϊ1110b��Ҳ����e��ת������ַ�Ϊ��д��E����
 
����������str1Ϊ"dec"��str2Ϊ"fab"���ϲ�Ϊ��decfab�����ֱ�ԡ�dca���͡�efb���������������Ϊ��abcedf����ת����Ϊ��5D37BF��
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

void xieryici(char *shuru)
{
	int deta=2,i,j,Current;
	for(i=deta;i<strlen(shuru);i++)
	{
		Current=shuru[i];
		j=i-deta;
		while(j>=0&&shuru[j]>Current)//ǰ���Ԫ�ش��ں���� ���ǰ��Ĵ���һ�������ƶ�
		{
			shuru[j+deta]=shuru[j];
			j=j-deta;
		}
		shuru[j+deta]=Current;
	}
}

void Toupper(char &xiaoxie)
{
	if(xiaoxie<='z'&&xiaoxie>='a')
	xiaoxie=xiaoxie-('z'-'Z');
}

void change(char *shuru)
{
	int i;
	for(i=0;i<strlen(shuru);i++)
	{
		if(shuru[i]<='9'&&shuru[i]>='0')
		{
			shuru[i]=shuru[i]-'0';
			shuru[i]^=0x0f;

		//	Toupper(shuru[i]);
		}
		if((shuru[i]<='Z'&&shuru[i]>='A'))
		{
			shuru[i]=shuru[i]-'A';
			shuru[i]^=0x0f;
			
	//		Toupper(shuru[i]);
		}
		if((shuru[i]<='z'&&shuru[i]>='a'))
		{
			shuru[i]=shuru[i]-'a';
			shuru[i]^=0x0f;
		
		//	Toupper(shuru[i]);
		}
	}

}
int main(void)
{
	char shuru1[100]={0};
	char shuru2[100]={0};
	char shuru[200]={0};

    scanf("%s",shuru1);
	scanf("%s",shuru2);

	strcat(shuru1,shuru2);
	printf("%s\n",shuru1);

	xieryici(shuru1);
	printf("%s\n",shuru1);

	change(shuru1);
	printf("%s\n",shuru1);


    system("pause");
    return 0;
}

/*����ʱ�䣺 2016-07-16 10:48:39
  �������⣺�����������
  ���Ĺ��ܣ�ʹ��strcat���������ַ��� ʹ��ϣ������Ķ���Ԫ�ط������� ���ö�0x0f���Ե���λȡ�� ����λ����
*/