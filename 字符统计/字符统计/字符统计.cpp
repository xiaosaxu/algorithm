/*��ʼʱ�䣺 2016-08-14 09:53:26
ʵ�ֹ��ܣ�����һ���ַ��������ַ��еĸ���Ӣ���ַ������֣��ո����ͳ�ƣ��ɷ������ã�
    ����ͳ�Ƹ����ɶൽ�����ͳ�ƽ�������ͳ�Ƶĸ�����ͬ������ASII����С�����������
    ���Ŀǰ��ͳ�ƽ��������ͳ��
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int fuhe(char shuru)
{
	if((shuru<='Z'&&shuru>='A')||(shuru<='z'&&shuru>='a')||(shuru<='9'&&shuru>='0')||shuru==' ')
		return 1;
	else
		return 0;
}

int comp(int a,int b)
{
	return a>b;
}
int main(void)
{
    char shuru1[10000];
	char *shuru=shuru1;
    int	book[300]={0};
	int book2[300]={0};
	int i=0,j=0;

	gets(shuru);

	if(strlen(shuru)==0)
		return 0;

	for(i=0; i<strlen(shuru); i++)
	{
		if(fuhe(shuru[i]))
		{
			book[shuru[i]]++;
			book2[shuru[i]]++;
		}
	}

	sort(book,book+300,comp);


	for(i=0; i<300&&book[i]>0; i++)
	{
		for(j=0;j<300; j++)
			if(book[i]==book2[j])
			{
				printf("%c",j);
				book2[j]=0;
				break;
			}
	}
	printf("\n");
    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-08-14 10:21:46
  �������⣺
  ���Ĺ��ܣ� ʹ���������鱣�� һ������ԭʼ���кͳ��ֵĹ�ϵ һ���������� ��sortĬ�ϴ�С�������� ��Ϊ������ŵ����� �������� ��ͬ���С�� 
				��ÿһ������ ����һ�������н��б�������С���󣩣������ͬ�������� ��Ӵ�С���б����� ��Ҫ����255��ƽ�� ���һ�������� ��ֹ�´��ҵ�
*/