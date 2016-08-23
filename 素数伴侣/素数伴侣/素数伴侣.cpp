/*开始时间： 2016-08-15 15:54:14
实现功能：
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int isprim(int data)
{
	if(data==2) return 1;
	for(int i=2; i<data/2+1; i++)
	{
		if(data%i==0)
			return 0;
	}
	return 1;
}

int main(void)
{
    
	int shuru[100]={0};
	int num=0;
	int i,j,k;
	int duishu=0,max=0;

	scanf("%d",&num);

	for(i=0; i<num; i++)
	{
		scanf("%d",&shuru[i]);
	}

	sort(shuru,shuru+num);

	do
	{
		duishu=0;

		for(i=0; i<=num-2;i+=2 )
		{
			if(isprim(shuru[i]+shuru[i+1]))
				duishu++;
		}
		if(max<duishu)
			max=duishu;
		
	}while(next_permutation(shuru,shuru+num));



	printf("%d\n",max);
    system("pause");
    return 0;
}
/*结束时间： 2016-08-15 16:10:38
  存在问题：
  核心功能： 使用algorithem 的 全排列函数 next_permutation
*/