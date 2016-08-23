/*开始时间： 2016-07-16 09:00:46
实现功能：
按照指定规则对输入的字符串进行处理。
详细描述：
将输入的两个字符串合并。
对合并后的字符串进行排序，要求为：下标为奇数的字符和下标为偶数的字符分别从小到大排序。这里的下标意思是字符在字符串中的位置。
对排训后的字符串进行操作，如果字符为‘0’——‘9’或者‘A’——‘F’或者‘a’——‘f’，则对他们所代表的16进制的数进行BIT倒序的操作，并转换为相应的大写字符。
如字符为‘4’，为0100b，则翻转后为0010b，也就是2。转换后的字符为‘2’； 如字符为‘7’，为0111b，则翻转后为1110b，也就是e。转换后的字符为大写‘E’。
 
举例：输入str1为"dec"，str2为"fab"，合并为“decfab”，分别对“dca”和“efb”进行排序，排序后为“abcedf”，转换后为“5D37BF”
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

void xieryici(char *shuru)
{
	int deta=2,i,j,Current;
	for(i=deta;i<strlen(shuru);i++)
	{
		Current=shuru[i];
		j=i-deta;
		while(j>=0&&shuru[j]>Current)//前面的元素大于后面的 则把前面的大数一次往后移动
		{
			shuru[j+deta]=shuru[j];
			j=j-deta;
		}
		shuru[j+deta]=Current;
	}
}

void Toupper(char &xiaoxie)
{
	if(xiaoxie<='z'&&xiaoxie>='a')
	xiaoxie=xiaoxie-('z'-'Z');
}

void change(char *shuru)
{
	int i;
	for(i=0;i<strlen(shuru);i++)
	{
		if(shuru[i]<='9'&&shuru[i]>='0')
		{
			shuru[i]=shuru[i]-'0';
			shuru[i]^=0x0f;

		//	Toupper(shuru[i]);
		}
		if((shuru[i]<='Z'&&shuru[i]>='A'))
		{
			shuru[i]=shuru[i]-'A';
			shuru[i]^=0x0f;
			
	//		Toupper(shuru[i]);
		}
		if((shuru[i]<='z'&&shuru[i]>='a'))
		{
			shuru[i]=shuru[i]-'a';
			shuru[i]^=0x0f;
		
		//	Toupper(shuru[i]);
		}
	}

}
int main(void)
{
	char shuru1[100]={0};
	char shuru2[100]={0};
	char shuru[200]={0};

    scanf("%s",shuru1);
	scanf("%s",shuru2);

	strcat(shuru1,shuru2);
	printf("%s\n",shuru1);

	xieryici(shuru1);
	printf("%s\n",shuru1);

	change(shuru1);
	printf("%s\n",shuru1);


    system("pause");
    return 0;
}

/*结束时间： 2016-07-16 10:48:39
  存在问题：异或函数有问题
  核心功能：使用strcat（）连接字符串 使用希尔排序的二个元素分组排序 采用对0x0f异或对第四位取反 高四位不变
*/