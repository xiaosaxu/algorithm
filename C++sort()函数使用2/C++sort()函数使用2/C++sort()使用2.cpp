#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

//2016-07-10 21:48:31
//ʵ�� ������������ո���λ�ĺ͵Ĵ�С�������� �� �������ͬ����ԭ��ֵ�Ĵ�С�ɴ�С��������
using namespace std;

int wsum(int shuzi)
{
	int sum=0,temp;

	while(shuzi>0)
	{
		temp=shuzi%10;
		sum+=temp;
		shuzi/=10;
	}

	return sum;
}

int comp(int a,int b)
{
	if(wsum(a)!=wsum(b))
		return wsum(a)<wsum(b);
	else
		return a<b;

}

int main()
{
	int shuru[10],i;

	for(i=0;i<10;i++)
		scanf("%d",&shuru[i]);

	sort(shuru,shuru+10,comp);//ע��sort������ʹ�÷��� ֱ�ӰѺ�������Ϊ���� ������βεĸ��� Ĭ�ϴӴ�С���� ������ķ���ֵ�����˵��������״̬

		for(i=0;i<10;i++)
		printf("%d ",shuru[i]);


	system("pause");


}
//2016-07-10 22:05:23