/*��ʼʱ�䣺 2016-07-14 09:46:56
ʵ�ֹ��ܣ����������ַ��� ���ص�һ�����ֵ�������Ӵ� û���򷵻ؿ�
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
			for(k=0;str1[i+k]==str2[j+k]&&str1[i+k]!='\0'&&str2[j+k]!='\0';k++)//��ѭ����� �ٽ��бȽ�
				;
			if(k>max)//ע�������Ǵ��ںű�ʾ�ǵ�һ�γ��ֵ���ַ���  ����Ǵ��ڵ�����Ϊ�����ֵ����ͬ�ַ���
			{
				max=k;//����
				st=j;//��ʼλ��
			}
		}
	}

	char * ResultStr=(char *)malloc(max+1);

	for(i=0;i<max;i++)
		ResultStr[i]=str2[st++];

	ResultStr[max]='\0';//����������

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

/*����ʱ�䣺 2016-07-14 11:25:00
  �������⣺
  ���Ĺ��ܣ�1.ͨ������ѭ�� ע��������ѭ����Ϊ��Ϊ�˵ڶ������  ע�������ֻ���ҵ����������ֵ����ʼֵ  ���ܰѱȽϵĳ��򲿷ַ�������
			2.Ϊ�˽�������ڷ���ָ�� ָ������ʱ�ռ䱻�ͷŵ���� ����ʹ����malloc���� ע�� malocĬ�ϲ�����λΪ�ֽ� ��������Ϊvoid*��Ҫǿ��ת�����ܸ�ֵ
			3.ע��������������±�Ĺ�ϵ��������������������ڶ��������ʱ��Ĵ�С������ʹ��malloc�����ʱ�� �����������±�ֻ�ܵ��ȷ���Сһ��λ��
*/