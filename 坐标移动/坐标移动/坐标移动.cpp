/*开始时间： 2016-08-14 15:39:08
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

char shuru1[1000]={0};
char *shuru=shuru1;
int A=0,W=0,S=0,D=0;

void tongji(int st,int ed)
{
	int temp=0,j=0;
	while(shuru[st]==';')
		st++;
	while(shuru[ed]==';')
		ed--;

	//有效性判断
	if(!(shuru[st]=='A'||shuru[st]=='W'||shuru[st]=='S'||shuru[st]=='D'))
		return;
	for(int i=st+1;i<=ed; i++)
		if(shuru[i]>'9'||shuru[i]<'0')
			return;

	//提取数值 并处理
	for(int i=ed,j=0;i>=st+1; i--)
	{
		temp=temp+(shuru[i]-'0')*pow((double)10,j);
		j++;
	}

	if(shuru[st]=='A')
		A+=temp;
	if(shuru[st]=='W')
		W+=temp;
	if(shuru[st]=='S')
		S+=temp;
	if(shuru[st]=='D')
		D+=temp;


}



int main(void)
{
	int step[1000]={0};
	int i,j=1;

	gets(shuru);

	for(i=0;i<strlen(shuru); i++)
		if(shuru[i]==';')
			step[j++]=i;

	for(i=1; i<j; i++)
		tongji(step[i-1],step[i]);


	//printf("A %d W %d S %d D %d\n",A,W,S,D);
	printf("(%d,%d)\n",D-A,W-S);
    system("pause");
    return 0;
}
/*结束时间： 2016-08-14 16:07:16
  存在问题：
  核心功能：
*/