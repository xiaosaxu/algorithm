/*开始时间： 2016-08-15 10:54:20
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
	int biao[10000]={0};
	int index=0,value=0;
	int num=0;
	int i=0;
	int gectrl=1;
	scanf("%d",&num);

	for(i=0; i<num; i++)
	{
		scanf("%d %d",&index,&value);
		biao[index]+=value;

	}

	for(i=0; i<10000; i++)
		if(biao[i]!=0)
		{
 
				printf("%d\n%d\n", i, biao[i] );
				gectrl=0;
		}

		 
    system("pause");
    return 0;
}
/*结束时间： 2016-08-15 11:00:24
  存在问题：
  核心功能：
*/