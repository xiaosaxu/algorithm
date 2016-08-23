/*开始时间： 2016-07-11 15:59:26
实现功能：找出字符串中第一个只出现一次的字符
详细描述：
接口说明
原型：
bool FindChar(char* pInputString, char* pChar);
输入参数：
char* pInputString：字符串
输出参数（指针指向的内存区域保证有效）：
char* pChar：第一个只出现一次的字符
如果无此字符 请输出'.'
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
	int i;
	char shuru[100],book[255]={0};
	char * zfchuan=shuru;
	gets(zfchuan);

	for(i=0;i<strlen(zfchuan);i++)//疑问：空格能通过gets读入，能被strlen识别吗？
		book[zfchuan[i]]++;

	for(i=0;i<strlen(zfchuan);i++)
		if(book[zfchuan[i]]==1)
		{
			printf("%c\n",zfchuan[i]);
			system("pause");
			return 0;
		}
	printf(".\n");
    system("pause");
    return 0;
}

/*结束时间： 2016-07-11 16:10:02
  存在问题：疑问：空格能通过gets读入，能被strlen识别吗？ 答：能识别 且能输出空格  采用测试案例 输入 1122 k 44 输出 k 
  核心功能：
*/