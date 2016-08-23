/*开始时间： 2016-08-14 19:47:23
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    
	char shuru1[100]={0};
	char *shuru=shuru1;
	int modNumber=0;

	scanf("%s %d",shuru, &modNumber);

	long sum = 0;
    //将“14689”看成多项式相加的和，即1*10^5+4*10^4+6*10^3+8*10^2+9*10^1，每一项如果看成X,Y,Z
    ///结合一些模运算的性质来考虑，比如，对多个数字的相加再求模和先对中间部分结果求模再相加后面的数再求模的结果是一样的
    //即  (X+Y+Z)modP =((X+Y)modP+ Z)modP = ((XmodP +Y)modP+Z)modP 
    //由此可以推出下面的代码：
    for (int i = 0; i < strlen(shuru); ++i)
    {

        sum = sum*10 + shuru[i]-'0';//这里要把每个字符的ASCII码减去48成为数字
       
        sum %= modNumber;
        printf("余数：%ld\n", sum);
    }


    system("pause");
    return 0;
}