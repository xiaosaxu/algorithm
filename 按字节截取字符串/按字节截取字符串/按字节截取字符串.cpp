/*��ʼʱ�䣺 2016-08-01 23:19:40
ʵ�ֹ��ܣ�
��дһ����ȡ�ַ����ĺ���������Ϊһ���ַ������ֽ��������Ϊ���ֽڽ�ȡ���ַ���������Ҫ��֤���ֲ����ذ����
��"��ABC"4��Ӧ�ý�Ϊ"��AB"������"��ABC��DEF"6��Ӧ�����Ϊ"��ABC"������"��ABC+���İ��"�� 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
	char shuru[100] = {0};
	int num = 0,i,sum = 0;

	scanf("%s %d", shuru, &num);
/*
	for(i=0;i<sizeof(shuru);i++)
		printf("%c ",shuru[i]);//��ӡassic��֪ ���ֵ��ַ�assicС��0 �����ж�

	printf("\n");
*/
	for (i=0; i<num; i++)
		if (shuru[i] < 0)
			sum++;

	if(sum%2 == 0) 
		shuru[num] = '\0';
	else
		shuru[num-1] = '\0';

	printf("%s\n", shuru);


    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-08-01 23:40:00
  �������⣺
  ���Ĺ��ܣ��������λ�������������м�ʱ�򣬵���ǰ����ж϶���С��0�� ��˲��ܼ򵥵��Թ涨�ַ�����ǰ���ж� 
			��������ô�ӡ�涨�ַ���֮ǰ�԰����ĺ����ַ�����ͳ�ƣ�һ�����������ַ���assic��С��0������Ϊż����ֱ�Ӵ�ӡ ��Ϊ��������ǰ��һ��
			���ô�ӡ�ַ�������ʽ�����ӡ
*/