/*��ʼʱ�䣺 2016-07-18 16:18:12
ʵ�ֹ��ܣ�ɾ���м� ��������
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
	char shuru[150]={0};
	int i=0,j,k;

	scanf("%s",shuru);

	while(shuru[i]=='*')
		i++;
	for(j=strlen(shuru)-1;shuru[j]=='*';j--)
		;

	for(k=i;k<=j;k++)
		if(shuru[k]=='*')
			shuru[k]='#';

	for(i=0;i<strlen(shuru);i++)
		if(shuru[i]=='#')
			continue;
		else
		printf("%c",shuru[i]);

	printf("\n");

    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-07-18 16:30:57
  �������⣺
  ���Ĺ��ܣ� ʹ��ͷβ����ָ�� ָ���*�ŵ��ַ�
*/