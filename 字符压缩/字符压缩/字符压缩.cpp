/*��ʼʱ�䣺 2016-08-14 17:18:32
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
	char shuru1[1000]={0};
	char *shuru=shuru1;
	int sum=0,i=0;

	gets(shuru);

	for( i=1; i<strlen(shuru); i++)
		if(shuru[i-1]==shuru[i])
		{
			sum++;
		}
		else
		{
			if(sum!=0)
				printf("%d",sum+1);
			printf("%c",shuru[i-1]);

			sum=0;
		}

		if(sum!=0)
		    printf("%d",sum+1);
		printf("%c",shuru[i-1]);

    system("pause");
    return 0;
}

/*����ʱ�䣺 2016-08-14 17:27:00
  �������⣺
  ���Ĺ��ܣ��������else����ֱ���˳��ˣ�������֮�󵥶���һ���ж� ʵ�����Ѿ������
*/