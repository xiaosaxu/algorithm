/*��ʼʱ�䣺 2016-07-12 16:53:08
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;


int findstr(char * str1,char *str2)
{
	char * pstr=str1,*psub=str2,*yuanshi=str1;
	for(str1;*str1;str1++)//�Ը�������ѭ�� ���������е�ÿһ��ÿһ���ַ�
	{
		psub=str2;//���¸�ֵ
		pstr=str1;//�������ڸ��ַ��� **ָ��λ��** ��ÿһ������ɨ�裩 (��ָ��λ���Ǿ��Ե�λ�ã���������ȡֵ �� ��ӡ�ַ�������ʼ��ַ��\0��)
		
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

/*����ʱ�䣺 2016-07-12 17:17:41
  �������⣺
  ���Ĺ��ܣ���������ÿ��ѭ��ʱʹ���Ѿ�ѭ������λ����Ϊ��ʼ�ıȽ���  ��һ��ƥ��֮����������ѭ���������ַ����Ľ�����־�����жϣ� �ַ���������־����*str=='\0'
*/