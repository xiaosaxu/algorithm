/*开始时间： 2016-07-10 22:13:29
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

void Ten2N(int a,int N)
{
	int result=0,temp,i=0,j=a;
	char aa[20]={0};
	while(a>0)
	{
		temp=a%N;

		if(temp<10)
		aa[i++]=temp+'0';
		else
		aa[i++]='a'+temp-10;

		a/=N;
	}
	printf("10进制数%d转化成%d进制数为",j,N);

	for(j=i-1;j>=0;j--)
	printf("%c",aa[j]);

	printf("\n");


}

void N2Ten(int N,int a)//最后应该考虑成字符串型  可以改进的地方
{
	int temp,i=0,sum=0,j=a;
	while(a>0)
	{
		temp=a%10;
		sum=sum+temp*pow((double)N,(double)i);
		i++;
		a/=10;
	}
	printf("%d进制数%d转化成10进制数为 %d\n",N,j,sum);
}

int main(void)
{
 //10进制转化成N进制   

	Ten2N(2012,16);

	N2Ten(5,213);

	system("pause");
    
	return 0;
}

/*开始时间： 2016-07-10 23:10:00
实现功能：
*/


/*开始时间： 2016-07-10 23:13:11
实现功能：

核心代码：
		sum=sum+temp*pow((double)N,(double)i);




	while(a>0)
	{
		temp=a%N;

		if(temp<10)
		aa[i++]=temp+'0';
		else
		aa[i++]='a'+temp-10;

		a/=N;
	}


*/