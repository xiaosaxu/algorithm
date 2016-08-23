/*开始时间： 2016-07-11 16:14:14
实现功能：输入n个整数，输出其中最小的k个。
详细描述：
接口说明
原型：
bool GetMinK(unsignedint uiInputNum, int * pInputArray, unsignedint uiK, int * pOutputArray);
输入参数：
     unsignedint uiInputNum //输入整数个数
int * pInputArray  //输入整数数组
unsignedint uiK   //需输出uiK个整数
输出参数（指针指向的内存区域保证有效）：
    int * pOutputArray //最小的uiK个整数
返回值：
        false 异常失败
          true  输出成功
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    int num,k,i,shuru[1024];
	scanf("%d",&num);
	scanf("%d",&k);

	for(i=0;i<num;i++)
		scanf("%d",&shuru[i]);

	sort(shuru,shuru+num);

	for(i=0;i<k-1;i++)
	printf("%d ",shuru[i]);
	printf("%d\n",shuru[k-1]);
    system("pause");

    return 0;
}

/*结束时间： 2016-07-11 16:33:59
  存在问题：题意的理解 先输入 总个数 在输入要求输出的数的数量
  核心功能：sort()函数的最简单使用 使用c++     （sort复习：包含头文件 #include<algorithm> using namespace std;   sort(st,st+shift,comp);）
*/