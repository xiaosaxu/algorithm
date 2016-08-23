/*开始时间： 2016-07-15 09:12:38
实现功能：A B两个数最小公倍数
描述	
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
知识点	循环,位运算
运行时间限制	10M
内存限制	128
输入	
输入两个正整数A和B。
输出	
输出A和B的最小公倍数。
样例输入	5 7
样例输出	35

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    int a,b,i;

	scanf("%d %d",&a,&b);

	for(i=a;!(i%a==0&&i%b==0);i++)
		;

	printf("%d\n",i);


    system("pause");
    return 0;
}

/*结束时间： 2016-07-15 09:19:50
  存在问题：
  核心功能：考虑到 输入 2 和 12 时候程序能识别出12来 注意循环的起始标志
*/