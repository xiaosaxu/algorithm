/*��ʼʱ�䣺 2016-08-14 10:25:48
ʵ�ֹ��ܣ���һ���ַ���str�����ݵߵ��������������str�ĳ��Ȳ�����100���ַ��� �磺���롰I am a student���������tneduts a ma I����
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std; 

int main(void)
{
    char shuru1[1000];
	char *shuru=shuru1;
	int pt=0,pw=0;
	char temp;

	gets(shuru);

	for(pt=0, pw=strlen(shuru)-1;pt<pw;)
	{
		temp=shuru[pt];
		shuru[pt]=shuru[pw];
		shuru[pw]=temp; 
		pt++,pw--;
	}

	printf("%s\n", shuru);

    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-08-14 10:38:22
  �������⣺
  ���Ĺ��ܣ�
*/