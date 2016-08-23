/*开始时间： 2016-08-14 10:50:36
实现功能：
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std; 

int comp(char *str1,char *str2)
{
	 if(strcmp(str1,str2)>0)
		 return 0;
	 else
		 return 1;
}

int main(void)
{
	char shuru[1000][1000]={0};
	char temp[10000]={0};
	int num=0;
	int i=0,j=0;

	scanf("%d", &num);

	for(i=0;i<num; i++)
		scanf("%s", shuru[i]);

	for(i=0; i<num; i++)
		for(j=1; j<num-i; j++)
			if(strcmp(shuru[j-1],shuru[j])>0)
			{
				strcpy(temp,shuru[j-1]);
				strcpy(shuru[j-1],shuru[j]);
				strcpy(shuru[j],temp);
			}

	for(i=0; i<num; i++)
	{
	printf("%s\n", shuru[i]);
	
	}


    system("pause");
    return 0;
}

/*结束时间： 2016-08-14 11:10:17
  存在问题：
  核心功能：
*/
