/*开始时间： 2016-08-07 16:45:12
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
	int i=0,temp=0;
	char shuchu[100]={0};

	scanf("%d",&shuru);

	if(shuru==0)
	{
		printf("0\n");
		return 0;
	}

	while(shuru > 0)
	{
		temp=shuru%12;

		if(temp>=10)
			temp='A'+temp-10;
		else
			temp=temp+'0';

		shuchu[i++] = temp;

		shuru/=12;
	}

	for(i=i-1; i >= 0; i--)
		printf("%c",shuchu[i]);

	printf("\n");

    system("pause");
    return 0;
}

/*结束时间： 2016-08-07 16:57:29
  存在问题： i最后比原来大一 要减去 for(i=i-1; i >= 0; i--)  输入要加上&符号 负责就是输入到地址0处
  核心功能： 对12取余数 作为最低位 然后除以12 用该数取余得次高位  依次循环 循环结束条件为原数等于0
*/