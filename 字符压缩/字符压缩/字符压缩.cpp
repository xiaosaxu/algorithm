/*开始时间： 2016-08-14 17:18:32
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
	char shuru1[1000]={0};
	char *shuru=shuru1;
	int sum=0,i=0;

	gets(shuru);

	for( i=1; i<strlen(shuru); i++)
		if(shuru[i-1]==shuru[i])
		{
			sum++;
		}
		else
		{
			if(sum!=0)
				printf("%d",sum+1);
			printf("%c",shuru[i-1]);

			sum=0;
		}

		if(sum!=0)
		    printf("%d",sum+1);
		printf("%c",shuru[i-1]);

    system("pause");
    return 0;
}

/*结束时间： 2016-08-14 17:27:00
  存在问题：
  核心功能：最后不满足else条件直接退出了，所以在之后单独做一次判断 实际上已经求出来
*/