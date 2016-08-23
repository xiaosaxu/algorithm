/*开始时间： 2016-07-12 16:53:08
实现功能：
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;


int findstr(char * str1,char *str2)
{
	char * pstr=str1,*psub=str2,*yuanshi=str1;
	for(str1;*str1;str1++)//对父串进行循环 遍历父串中的每一个每一个字符
	{
		psub=str2;//重新赋值
		pstr=str1;//更新现在父字符串 **指针位置** （每一个都会扫描） (该指针位置是绝对的位置，可以用来取值 和 打印字符串（起始地址到\0）)
		
		while(*psub==*pstr&&*psub!='\0')
		{
			psub++;
			pstr++;
		}
		if(*psub=='\0')
			return (str1-yuanshi+1);
	}
	return -1;
}
int main(void)
{
    
	char *str1="hell3333oxu12";
	char *str2="xu";

	
	printf("%d",findstr(str1,str2));

    system("pause");
    return 0;
}

/*结束时间： 2016-07-12 17:17:41
  存在问题：
  核心功能：核心在于每次循环时使用已经循环到的位置作为起始的比较量  有一个匹配之后再在里面循环（对子字符串的结束标志进行判断） 字符串结束标志采用*str=='\0'
*/