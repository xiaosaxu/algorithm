/*开始时间： 2016-08-14 07:39:40
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    int data;
	int num=0;

	scanf("%d",&data);
    if(data<0)
	{
		data=0-data;
		num=1;
	}
	while(data)
	{
		if(data & 1)
		{
			num++;
		}

		data=data>>1;
	}
	printf("%d\n",num);

    system("pause");
    return 0;
}