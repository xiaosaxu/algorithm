/*开始时间： 2016-08-14 09:11:49
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
	int shuru=0;
	int flag=1;

    while(scanf("%d", &shuru)!=EOF)
	{
		flag=1;
		if(shuru<0)
		{
			shuru=0-shuru;
			flag=-1;
		}
		for(double i=0; i<=shuru; i++)
			if(shuru==i*i*i)
			{
				printf("%0.1f",i*flag);
				break;
			}
	}
    system("pause");
    return 0;
}