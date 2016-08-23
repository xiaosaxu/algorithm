#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

//2016-07-10 21:48:31
//实现 对输入的数按照各个位的和的大小进行排序 ， 如果和相同按照原数值的大小由大到小进行排序
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

	sort(shuru,shuru+10,comp);//注意sort函数的使用方法 直接把函数名作为参数 避免的形参的干扰 默认从大到小排序 函数里的返回值的情况说明了排序状态

		for(i=0;i<10;i++)
		printf("%d ",shuru[i]);


	system("pause");


}
//2016-07-10 22:05:23