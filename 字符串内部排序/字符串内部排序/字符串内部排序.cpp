/*开始时间： 2016-07-14 20:38:30
实现功能：
编写一个程序，将输入字符串中的字符按如下规则排序。
规则1：英文字母从A到Z排列，不区分大小写。
      如，输入：Type 输出：epTy
规则2：同一个英文字母的大小写同时存在时，按照输入顺序排列。
    如，输入：BabA 输出：aABb
规则3：非英文字母的其它字符保持原来的位置。
    如，输入：By?e 输出：Be?y
样例：
    输入：
   A Famous Saying: Much Ado About Nothing(2012/8).
    输出：
   A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int iszimu(char zifu)
{
	if((zifu>='a'&&zifu<='z')||(zifu>='A'&&zifu<='Z'))
		return 1;
	else
		return 0;
}

int comp(char a,char b)
{
	if(a>='A'&&a<='Z')
		a+='a'-'A';

	if(b>='A'&&b<='Z')
		b+='a'-'A';

	return a<b;
}

int main(void)
{
	char shuru1[200]={0},tiqu1[200]={0};
	char *shuru=shuru1;
	char *tiqu=tiqu1;
	int i,j=0;

	gets(shuru);

	for(i=0;i<strlen(shuru);i++)
		if(iszimu(shuru[i]))
			tiqu[j++]=shuru[i];
	tiqu[j]='\0';

	stable_sort(tiqu,tiqu+strlen(tiqu),comp);//提取排序完成

	for(i=0,j=0;i<strlen(tiqu);i++)
	{
			while(0==iszimu(shuru[j]))
				j++;
			shuru[j++]=tiqu[i];
	}
	printf("%s\n",tiqu);
	printf("%s\n",shuru);

    system("pause");
    return 0;
}
/*结束时间： 2016-07-14 21:07:02
  存在问题：
  核心功能：先把字母从原来的输入字符串中提取出来 进行排序 再把排好顺序的字符串 覆盖掉原来输入的字符串中 遇到非字符则跳过
*/