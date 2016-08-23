/*开始时间： 2016-07-14 13:51:58
实现功能： 素数即除了本身和1以外不能被其他比他小的数整除的数
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    int shuru=0,i,j;

	scanf("%d",&shuru);

	if(shuru<=0)
		printf("input error\n");
for(j=2;j<=shuru;j++) //对每一个数进行判断
{
	int flag=1;
	for(i=2;i<j/2+1;i++)//判定某个数是否为素数 注意只要循环到一般就可以了
		if(j%i==0)
		{
			flag=0;
			break;//这个循环是对所有的可能遍历的只要找到一个就退出
		}
	if(flag==1) printf("%d ",j);
}

    system("pause");
    return 0;
}
/*结束时间： 2016-07-14 14:33:19
  存在问题：
  核心功能：
*/