/*��ʼʱ�䣺 2016-07-11 16:14:14
ʵ�ֹ��ܣ�����n�����������������С��k����
��ϸ������
�ӿ�˵��
ԭ�ͣ�
bool GetMinK(unsignedint uiInputNum, int * pInputArray, unsignedint uiK, int * pOutputArray);
���������
     unsignedint uiInputNum //������������
int * pInputArray  //������������
unsignedint uiK   //�����uiK������
���������ָ��ָ����ڴ�����֤��Ч����
    int * pOutputArray //��С��uiK������
����ֵ��
        false �쳣ʧ��
          true  ����ɹ�
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    int num,k,i,shuru[1024];
	scanf("%d",&num);
	scanf("%d",&k);

	for(i=0;i<num;i++)
		scanf("%d",&shuru[i]);

	sort(shuru,shuru+num);

	for(i=0;i<k-1;i++)
	printf("%d ",shuru[i]);
	printf("%d\n",shuru[k-1]);
    system("pause");

    return 0;
}

/*����ʱ�䣺 2016-07-11 16:33:59
  �������⣺�������� ������ �ܸ��� ������Ҫ���������������
  ���Ĺ��ܣ�sort()���������ʹ�� ʹ��c++     ��sort��ϰ������ͷ�ļ� #include<algorithm> using namespace std;   sort(st,st+shift,comp);��
*/