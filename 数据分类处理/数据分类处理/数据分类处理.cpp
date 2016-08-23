/*开始时间： 2016-08-08 11:33:32
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
     int Iin=0,Rin=0;
	 int i=0,j=0, k=0;
	 int weishu=0;
	 int temp=0,sum=0;

	scanf("%d",&Iin);
	int * shuruI=(int *)malloc(sizeof(int)*Iin);

	for(i=0; i<Iin; i++)
		scanf("%d",&shuruI[i]);



	scanf("%d",&Rin);
	int * shuruR=(int *)malloc(sizeof(int)*Rin);

	for(i=0; i<Rin; i++)
		scanf("%d",&shuruR[i]);

	sort(shuruR,shuruR+Rin);//排序

	for(i=0; i<Rin; i++)
	{
		if(i>0&&shuruR[i]==shuruR[i-1])
			continue;
		weishu=shuruR[i]/10+1;

		for(j=0; j<Iin; j++)//对Iin中的每个数进行判断
		{
			temp=shuruI[j];
			while(temp>0)
			{
							
				sum=shuruI[j]%(10*weishu);
				if(sum==shuruR[i])
				{
					printf("%d 匹配 %d\n",shuruI[j],shuruR[i]);
					break;
				}
				else
					temp/=10;

			}
		}

	}




	for(i=0; i<Iin; i++)
		printf("%d ",shuruI[i]);


	for(i=0; i<Rin; i++)
		printf("%d ",shuruR[i]);

    system("pause");
    return 0;
}