/*开始时间： 2016-08-14 10:38:56
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;



int main(void)
{
    
	char shuru1[1000];
	char *shuru=shuru1;

	gets(shuru);

	for(int i=strlen(shuru)-1; i>=0; i--)
		printf("%c", shuru[i]);

	printf("\n");

    system("pause");
    return 0;
}

/*结束时间： 2016-08-14 10:44:01
  存在问题：
  核心功能：
*/
