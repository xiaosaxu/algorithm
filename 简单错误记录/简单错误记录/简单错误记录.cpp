/*开始时间： 2016-08-14 22:08:53
实现功能：
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct record_tag
{
	char * name;
	int line;
	int countflag;
}Record;

int main(void)
{
	Record ERecord[1000]={0};
	char shuru[1000][1000]={0};
	int i=0,j=0,k=0;

	while(gets(shuru[i++])!=NULL);

	for(int j=0; j<i; j++)
	{
		int kg=0;
		while(shuru[j][kg]!=' ')
			kg++;

		int xh=kg;
		while((shuru[j][xh]!='\\') && (xh>0))
			xh--;
		if(xh==0)
			xh=-1;

		int len=kg-xh;
		if(len>16)
			len=17;
		char *name_temp=(char *)malloc(len);
		for(k=len-2; k>=0; k--)
			name_temp[k]=shuru[j][--kg];
		name_temp[len-1]='\0';


		printf("%s",name_temp);

		
	}


    system("pause");
    return 0;
}