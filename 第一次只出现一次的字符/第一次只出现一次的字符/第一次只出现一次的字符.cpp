/*��ʼʱ�䣺 2016-07-11 15:59:26
ʵ�ֹ��ܣ��ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
��ϸ������
�ӿ�˵��
ԭ�ͣ�
bool FindChar(char* pInputString, char* pChar);
���������
char* pInputString���ַ���
���������ָ��ָ����ڴ�����֤��Ч����
char* pChar����һ��ֻ����һ�ε��ַ�
����޴��ַ� �����'.'
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

	for(i=0;i<strlen(zfchuan);i++)//���ʣ��ո���ͨ��gets���룬�ܱ�strlenʶ����
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

/*����ʱ�䣺 2016-07-11 16:10:02
  �������⣺���ʣ��ո���ͨ��gets���룬�ܱ�strlenʶ���� ����ʶ�� ��������ո�  ���ò��԰��� ���� 1122 k 44 ��� k 
  ���Ĺ��ܣ�
*/