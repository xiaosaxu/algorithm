/*��ʼʱ�䣺 2016-08-07 16:45:12
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    int shuru=0;
	int i=0,temp=0;
	char shuchu[100]={0};

	scanf("%d",&shuru);

	if(shuru==0)
	{
		printf("0\n");
		return 0;
	}

	while(shuru > 0)
	{
		temp=shuru%12;

		if(temp>=10)
			temp='A'+temp-10;
		else
			temp=temp+'0';

		shuchu[i++] = temp;

		shuru/=12;
	}

	for(i=i-1; i >= 0; i--)
		printf("%c",shuchu[i]);

	printf("\n");

    system("pause");
    return 0;
}

/*����ʱ�䣺 2016-08-07 16:57:29
  �������⣺ i����ԭ����һ Ҫ��ȥ for(i=i-1; i >= 0; i--)  ����Ҫ����&���� ����������뵽��ַ0��
  ���Ĺ��ܣ� ��12ȡ���� ��Ϊ���λ Ȼ�����12 �ø���ȡ��ôθ�λ  ����ѭ�� ѭ����������Ϊԭ������0
*/