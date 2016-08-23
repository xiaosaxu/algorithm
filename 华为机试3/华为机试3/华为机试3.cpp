/*开始时间： 2016-07-18 17:14:13
实现功能：
输入一段英文文本，用程序统计出现频率最高和第二高的两个单词。
 
限制条件：
（1）英文文本中仅出现这四类字符：空格( )、英文逗号(,)、英文句号(.)、英文大小写字母（a-z、A-Z）；
（2）单词之间的分隔符仅考虑这三种：空格( )、英文逗号(,)、英文句号(.)；
（3）仅大小写不同的单词算同一个单词；
（4）不用考虑两个单词出现次数相同的情况；
（5）返回的单词统一用小写字母返回；

例如：
输入字符串"Hello world, i said hello world to the world"，输出"world,i"；
输入字符串"Somebody like somebody, i do not like it"，输出"somebody,i"；

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct danci
{
	char * word;
	int cishu;
	int countflag;
}tongji;

tongji AllDanCi[400]={0};

int index=0;

void FenPei(char shuru[],int st,int ed)
{
	char temp;
	int i,tt=0;

	char *danci;
	

		//判断是有特殊符号
		while(shuru[st]==','||shuru[st]=='.'||shuru[st]==' ')//采用这种机制也能实现保留符号位置不变的翻转
			st++;
		while(shuru[ed]==','||shuru[ed]=='.'||shuru[ed]==' ')
			ed--;

		danci=(char *)malloc(ed-st+1+1);

			for(i=st;i<=ed;i++)
			{
				//printf("%c",shuru[i]);
				danci[tt++]=shuru[i];
			}
		danci[tt]='\0';

		AllDanCi[index].word=danci;

		//printf("%s",AllDanCi[index].word);
		index+=1;
		//printf("\n");
	
}



int cmp(tongji s1,tongji s2)
{
	if(s1.cishu>s2.cishu)
		return 1;
	else 
		return 0;
}

int main(void)
{
	

	char shuru1[1050]={0};
    char *shuru=shuru1;
	int i=0,j=0,k=0,kge[300]={0};

	gets(shuru);

	if(strlen(shuru)==0)
		return 0;
	j=1;//第一个元素位置
	for(i=0;i<strlen(shuru);i++)
	{
		if(shuru[i]==' ')					//提取空格
			kge[j++]=i;
		if(shuru[i]>='A'&&shuru[i]<='Z')	//大小写转换
			shuru[i]=shuru[i]+('z'-'Z');
	}
	
	kge[j]=strlen(shuru)-1;//最后一个元素位置 这里使用了减一

	for(k=1;k<=j;k++)//把每个单词放进对应的结构体中
		FenPei(shuru,kge[k-1],kge[k]);

   for(i=0;i<index;i++)//出现次数统计
   {
	   if(AllDanCi[i].countflag==1)
		   continue;
	   for(j=0;j<index;j++)
	   if(strcmp(AllDanCi[i].word,AllDanCi[j].word)==0)
	   {
			AllDanCi[i].cishu+=1;
			AllDanCi[j].countflag=1;

	   }

	//   printf("%s %d\n",AllDanCi[i].word,AllDanCi[i].cishu);

   }

  // printf("\n\n");
    stable_sort(AllDanCi,AllDanCi+index,cmp);//按照出现次数排序

    printf("%s,",AllDanCi[0].word);
	if(index>1)
    printf("%s\n",AllDanCi[1].word);
	else
    printf("%s\n",AllDanCi[0].word);



    system("pause");
    return 0;
}
/*结束时间： 2016-07-18 18:53:38
  存在问题：
  核心功能：使用结构体存放单词 以及其出现的次数 统计时使用结构体的标志位防止重复统计 
*/