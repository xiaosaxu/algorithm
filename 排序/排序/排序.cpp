/*开始时间： 2016-08-15 08:46:52
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int iszimu(char zimu)
{
	if((zimu<='z'&&zimu>='a') || (zimu<='Z'&&zimu>='A'))
		return 1;
	else 
		return 0;
}

int cmp(char a, char b)
{
	if(a<='z' && a>='a')
		a=a-('a'-'A');
	if(b<='z' && b>='a')
		b=b-('a'-'A');

	return a < b;

}
int main(void)
{
	char shuru[10000]={0};
	char tiqu[10000]={0};
	int i,j=0,k=0;

	gets(shuru);

	for(i=0; i<strlen(shuru); i++)
		if(iszimu(shuru[i]))
			tiqu[k++]=shuru[i];

	stable_sort(tiqu,tiqu+strlen(tiqu),cmp);

	

	for(i=0; i<strlen(shuru); i++)
		if(iszimu(shuru[i]))
			shuru[i] = tiqu[j++];


	printf("%s\n",shuru);

    system("pause");
    return 0;
}

/*结束时间： 2016-08-15 09:02:59
  存在问题：
  核心功能：
*/