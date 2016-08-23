/*开始时间： 2016-07-14 09:46:56
实现功能：输入两个字符串 返回第一个出现的最长公共子串 没有则返回空
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

char * FindMaxStr(const char *str1,const char *str2)
{
	int i=0,j=0,k=0;
	int st=0,max=0;
	for(i=0;str1[i]!='\0';i++)
	{
		for(j=0;str2[j]!='\0';j++)
		{
			for(k=0;str1[i+k]==str2[j+k]&&str1[i+k]!='\0'&&str2[j+k]!='\0';k++)//先循环完毕 再进行比较
				;
			if(k>max)//注意这里是大于号表示是第一次出现的最长字符串  如果是大于等于则为最后出现的最长相同字符串
			{
				max=k;//长度
				st=j;//起始位置
			}
		}
	}

	char * ResultStr=(char *)malloc(max+1);

	for(i=0;i<max;i++)
		ResultStr[i]=str2[st++];

	ResultStr[max]='\0';//这里必须加上

	return ResultStr;

}

int main(void)
{
	char shuru1[100]={0};
	char shuru2[100]={0};

	gets(shuru1);
	gets(shuru2);

	printf("%s\n",FindMaxStr(shuru1,shuru2));


	system("pause");

	return 0;
}

/*结束时间： 2016-07-14 11:25:00
  存在问题：
  核心功能：1.通过三次循环 注意第三层的循环是为了为了第二层服务  注意第三层只是找到连续的最大值和起始值  不能把比较的程序部分放在里面
			2.为了解决函数内返还指针 指针在临时空间被释放的情况 我们使用了malloc函数 注意 maloc默认参数单位为字节 返回类型为void*需要强制转化才能赋值
			3.注意数组的数量和下标的关系，数组的数量不仅体现在定义数组的时候的大小，还有使用malloc分配的时候 分配多大数组下标只能到比分配小一的位置
*/