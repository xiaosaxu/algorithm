/*��ʼʱ�䣺 2016-08-13 13:21:14
ʵ�ֹ��ܣ�
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int zhuanhua(char data)
{
	if(data<='9'&&data>='0')
		return data-'0';
	if(data<='F' && data>='A')
		return data-'A'+10;
}

int main(void)
{
	
	char shuru[100]={0};
	int jieguo=0,j=0;
	int temp;

	gets(shuru);

	for(int i=strlen(shuru)-1; i>1; i--)
	{
		temp=zhuanhua(shuru[i]);
		jieguo=jieguo+temp * pow((double)16,j++);
	}

	printf("%d\n", jieguo);

    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-08-13 13:33:22
  �������⣺
  ���Ĺ��ܣ�ע��16���� A��F֮����ֵ��ת��
*/