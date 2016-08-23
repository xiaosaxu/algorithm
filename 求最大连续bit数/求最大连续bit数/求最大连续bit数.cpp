/*开始时间： 2016-08-14 09:02:26
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std; 

int main(void)
{
    int shuru;
	int max=0,num=0;

	while(scanf("%d", &shuru)!=EOF)
	{
		max=0;
		num=0;
		while(shuru)
		{

			if(shuru&1)
			{
				num++;
			}
			else
			{
				num=0;
			}
			shuru=shuru>>1;

			if(num>max)
				max=num;
		}

		printf("%d\n", max);
	}
    system("pause");
    return 0;
}

/*结束时间： 2016-08-14 09:06:54
  存在问题：
  核心功能：
*/