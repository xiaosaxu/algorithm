/*开始时间： 2016-08-13 18:53:42
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

void nextindex(int & index,int num)
{
	index++;
	index=index%(num);
}

int main(void)
{
    
	int num=0,i;
	int huan[2000];
	int index=1;

	for(i=0; i<2000; i++)
		huan[i]=1;

	scanf("%d", &num);

	for(i=0; i<num; i++)
	{


		while(huan[index]==0)
		{
			nextindex(index,num);
		}
		nextindex(index,num);


		while(huan[index]==0)
		{
			nextindex(index,num);
		}
		nextindex(index,num);

		huan[index]=0;
		printf("%d ", index);
			
	}
    system("pause");
    return 0;
}