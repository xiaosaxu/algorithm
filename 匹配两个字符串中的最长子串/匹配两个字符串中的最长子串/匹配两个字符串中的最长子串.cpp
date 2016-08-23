/*开始时间： 2016-07-12 17:20:49
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int FindLen(char *shuru1,char * shuru2)
{
	char *s1,s2;
	int i,j,k,max=0;
	for(i=0;shuru1[i];i++)
		for(j=0;shuru2[j];j++)
		{
			for(k=0;(shuru1[i+k]==shuru2[j+k])&&(shuru1[i+k]||shuru2[j+k]);k++)
			{
				;
			}		
			if(k>max)
				max=k;
		}
	return max;
}

int main(void)
{
	char *str1="Hello world";
	char *str2="orwor";

	char *result=NULL;

	
printf("%d",FindLen(str1,str2));

    system("pause");
    return 0;
}