/*��ʼʱ�䣺 2016-07-12 15:59:58
ʵ�ֹ��ܣ�
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
	int i=0;
	char shuru1[100]={0};
	char *shuru=shuru1;

	gets(shuru);

	for(i=strlen(shuru)-1;i>=0;i--)
		if(shuru[i]==' ')
			break;
	if(i!=0)
		printf("%d\n",strlen(shuru)-i-1);
	else
		printf("%d\n",strlen(shuru));
    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-07-12 16:06:54
  �������⣺
  ���Ĺ��ܣ�strlen()���±�Ĺ�ϵ ����ֻ��һ�����ʵ����
*/