/*��ʼʱ�䣺 2016-08-13 14:01:16
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int prim(int data)
{
	for(int i=2; i<data/2+1; i++)
	{
		if(data%i==0)
			return 0;
	}
	return 1;
}

void yinzi(int shuru)
{
	if(shuru>0)
	for(int i=2; i<shuru; i++)
		if(shuru%i==0&&prim(i))//ע�⣡���� ������Ч���Ǳ�һ���� �� ��ȡģ�� ���Ϊ0
		{
			printf("%d ",i);
			yinzi(shuru/i);
			return;
		}
	printf("%d\n",shuru);
}

int main(void)
{
    
	int shuru=0;

	scanf("%d",&shuru);

	yinzi(shuru);

	//printf("%d",prim(shuru));

    system("pause");
    return 0;
}