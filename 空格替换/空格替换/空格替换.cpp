/*��ʼʱ�䣺 2016-08-29 16:48:59
ʵ�ֹ��ܣ����ַ�������Ŀո��滻��%20
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    int i,len;
	char shuru[1000]={0};
	char shuchu[1000]={0};

	gets(shuru);
	len=strlen(shuru);

	if(len==0)
		return 0;



	for(i=0; i<len; i++)
	{
		if(shuru[i]==' ')
			printf("%s","%20");
		else
			printf("%c",shuru[i]);
	}
	
	printf("\n");


	//��ԭ�������޸� ǰ�� ԭ���������㹻�� 
	//�������޸�ԭ������������Ҫ�½�һ����ʱ���� �������������ĳ��ȶ�̬��������� ֻҪ��������������Ƹĵ��Ϳ�����

	int kgenum=0,strnum=0;
	for(i=0; i<len; i++)
	if(shuru[i]==' ')
		kgenum++;

	strnum=len-1+kgenum*2;
	shuru[strnum+1]='\0';
	for(i=len - 1; i>= 0 ;i--)
	{
		if(shuru[i]==' ')
		{
			shuru[strnum--]='0';
			shuru[strnum--]='2';
			shuru[strnum--]='%';

		}
		else
			shuru[strnum--]=shuru[i];

	}

	printf("%s\n",shuru);
		

    system("pause");
    return 0;
}

/*����ʱ�䣺 2016-08-29 17:17:58
  �������⣺
  ���Ĺ��ܣ�ʹ������ָ�� �ֱ�ָ��ԭ������·��������Ľ�β
*/