/*��ʼʱ�䣺 2016-07-12 16:22:11
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

void deletechar(char* shuru,char shanchu)
{
	int i=0,j=0;
	while(shuru[i])
	{
		if(shuru[i]!=shanchu)//������Ϊ����ȡ������
			shuru[j++]=shuru[i];
		i++;
	}
	shuru[j]='\0';//����ǳ���Ҫ ��Ϊ��while()ѭ������ �����һ��\0�ַ���ʱ�����˳�ѭ���� ��˻ᶪʧ���ַ����Ľ�����־ ֮���ӡ��һֱ��ӡ��ԭ�ַ����Ľ����ط�
}
int main(void)
{
    
	char shuru1[100]={0},shanchu;
	char *shuru=shuru1;

	gets(shuru);

	scanf("%c",&shanchu);

	deletechar(shuru,shanchu);

	printf("%s",shuru);

    system("pause");
    return 0;
}

/*����ʱ�䣺 2016-07-12 16:36:23
  �������⣺
  ���Ĺ��ܣ�j��һ��ֻ����Ч�ַ�Ӱ����Լӱ���  ��i�Ǳ������е� ��Чλ��ᰤ������ ���һ��Ҫ�ǵü���'\n' �ַ���������־
*/