/*��ʼʱ�䣺 2016-07-14 13:51:58
ʵ�ֹ��ܣ� ���������˱����1���ⲻ�ܱ���������С������������
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    int shuru=0,i,j;

	scanf("%d",&shuru);

	if(shuru<=0)
		printf("input error\n");
for(j=2;j<=shuru;j++) //��ÿһ���������ж�
{
	int flag=1;
	for(i=2;i<j/2+1;i++)//�ж�ĳ�����Ƿ�Ϊ���� ע��ֻҪѭ����һ��Ϳ�����
		if(j%i==0)
		{
			flag=0;
			break;//���ѭ���Ƕ����еĿ��ܱ�����ֻҪ�ҵ�һ�����˳�
		}
	if(flag==1) printf("%d ",j);
}

    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-07-14 14:33:19
  �������⣺
  ���Ĺ��ܣ�
*/