/*开始时间： 2016-07-31 23:46:17
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

void print()
{
	char a;
	scanf("%c", &a);
	if(a!= '#')
		print();
	if(a!= '#') //注意函数返回之后从这里开始执行 打印之前的数
		printf("%c ",a);

}

int main(void)
{
    
	print();

    system("pause");
    return 0;
}

/*结束时间： 2016-07-31 23:49:50
  存在问题：
  核心功能：
*/