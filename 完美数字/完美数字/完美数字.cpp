/*��ʼʱ�䣺 2016-08-07 20:08:09
ʵ�ֹ��ܣ�
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{

	int XiaJie=0,ShangJie=0;
	int i;
	int num=0;

	scanf("%d %d", &XiaJie, &ShangJie);

	for(i=XiaJie; i<=ShangJie; i++)
		if(0==i%30)
			num++;
	printf("%d\n",num);

	system("pause");
	return 0;
}

/*����ʱ�䣺 2016-08-07 20:12:08
  �������⣺
  ���Ĺ��ܣ�
*/