/*开始时间： 2016-08-13 10:23:29
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    int total=0;
	int ID[1000]={0};//对于输入多个测试用里的条件


    while(scanf("%d",&total)!=EOF)
	{
  //ID=(int *)malloc(sizeof(int)*total);
	for(int i=0;i<1000;i++)//每次初始化
		ID[i]=-1;

    for(int i=0; i<total; i++)
        scanf("%d",&ID[i]);
    
//    for(int i=0; i<10; i++)
//	printf("%d\n",ID[i]);

    sort(ID,ID+1000);
    
	int i=0;
	while(ID[i]==-1)
		i++;
    printf("%d\n",ID[i]);

    for(int j=i+1; j<1000; j++)//结尾肯定是有数的 一直到结尾判断即可
        if(ID[j]!=ID[j-1])
            printf("%d\n",ID[j]);
	}
        system("pause");
   
    return 0;
}

/*结束时间： 2016-08-13 11:17:23
  存在问题：以后编程要把***思路***理清楚了 在草稿纸上写出来 分为那几个步骤 在把***边界条件***求清楚
  核心功能：
*/