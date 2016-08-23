/*开始时间： 2016-07-17 10:44:19
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

char *maxstr(char*shuru1,char* shuru2)
{
	int i,j,k,max=0,st=0;
	char *result;
	for(i=0;shuru1[i];i++)
		for(j=0;shuru2[j];j++)
		{
			for(k=0;(shuru2[j+k]==shuru1[i+k])&&shuru2[j+k];k++)
			;
				if(k>max)
				{
					st=j;
					max=k;
				}
		}	

	result=(char *)malloc(max);
	for(i=0;i<max;i++)
		result[i]=shuru2[st+i];
	result[max]='\0';

	return result;

}

int main(void)
{
	char shuru1[100]={0},shuru2[100]={0},*shuchu;

	scanf("%s",shuru1);
	scanf("%s",shuru2);

	shuchu=maxstr(shuru1,shuru2);
	printf("%s\n",shuchu);
    system("pause");
    return 0;
}