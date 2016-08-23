/*开始时间： 2016-08-15 21:58:15
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
	int a[1000]={0};
	int month=0;

	a[1]=1;
	a[2]=1;

	scanf("%d", &month);

	for(int i=3; i<=month; i++)
		a[i]=a[i-1]+a[i-2];

	printf("%d\n", a[month]);

    system("pause");
    return 0;
}
/*结束时间： 2016-08-15 22:02:45
  存在问题： 识别出斐波那契数列 1 1 2 3 5 。。。
  核心功能：
*/