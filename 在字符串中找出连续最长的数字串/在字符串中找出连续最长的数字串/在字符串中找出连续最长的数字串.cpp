/*��ʼʱ�䣺 2016-07-18 08:58:49
ʵ�ֹ��ܣ����ַ������ҳ�����������ִ�

����	
����һ���ַ�����
���	
����ַ�������������ַ��������ĳ��ȡ�
��������ַ���Ϊ�գ���ֻ���0
�� input: dadfsaf  output:0
��������	abcd12345ed125ss123058789
�������	123058789,9

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

void FindNumList(char * shuru)
{
	int i,k,st,max=0;
	for(i=0;i<strlen(shuru);i++)
	{
		for(k=0;shuru[i+k]!='\0'&&(shuru[i+k]<='9'&&shuru[i+k]>='0');k++)
			;
		if(k>max)
		{
		max=k;
		st=i;
		}
	}
	for(i=0;i<max;i++)
		printf("%c",shuru[st+i]);
	if(max>0)
	printf(",");
	printf("%d\n",max);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    
	char shuru[100];
	gets(shuru);
	

	FindNumList(shuru);

    system("pause");
    return 0;
}

/*����ʱ�䣺 2016-07-18 09:16:24
  �������⣺
  ���Ĺ��ܣ�
*/