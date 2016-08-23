/*开始时间： 2016-08-15 08:07:27
实现功能：
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;


int main(void)
{
	char shuru[1000]={0};
	int i,j,k;
	int pass=1;
	int len=0;

	while(gets(shuru)!=NULL)
	{


	len=strlen(shuru);

	if(len<=8)
	{
		pass=0;
	}

    int numflag=0, zmflag=0, ZMflag=0, otherflag=0;
	for(i=0; i<len; i++)
	{
		if(shuru[i]<='9'&&shuru[i]>='0')
			numflag=1;
		else
			if(shuru[i]<='z'&&shuru[i]>='a')
				zmflag=1;
		else
			if(shuru[i]<='Z'&&shuru[i]>='A')
				ZMflag=1;
		else
				otherflag=1;
	}
	if(numflag + zmflag + ZMflag + otherflag < 3)
	{
		pass=0;
	}

	for(i=0;i<len-3; i++)
		for(j=i+3; j<len; j++)
		{
			if(shuru[i]==shuru[j] && shuru[i+1]==shuru[j+1] && shuru[i+2]==shuru[j+2])
			{
				pass=0;
			}
		}

    if(pass==1)
			printf("OK\n");
	else
			printf("NG\n");


	for(i=0; i<1000; i++)
		shuru[i]=0;
	pass=1;

	}
  
    return 0;
}
/*结束时间： 2016-08-15 08:46:14
  存在问题：
  核心功能：
*/