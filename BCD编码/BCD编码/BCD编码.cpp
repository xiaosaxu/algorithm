/*��ʼʱ�䣺 2016-08-07 17:07:57
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(void)
{
	char shuru[50]={0};
	char *shuru1=shuru;
	int i,j,k;
	int temp[8]={0};
	int jisuan=0;

	scanf("%s",shuru1);

	int a=strlen(shuru1);
	if(1==strlen(shuru1)%2)
	{
		for(i=strlen(shuru1); i >=0; i--)
			shuru[i+1]=shuru[i];

		shuru[0]='0';
	}

	for(i=0;i <= strlen(shuru1)-2; i+=2)//�߽���������
	{
		for(k=0,j = i+1;j>=i; j--)
		{
			int zhuanhua=shuru[j]-'0';
			
			while(zhuanhua)
			{
			temp[k++]=zhuanhua%2;
			zhuanhua=zhuanhua/2;
			}

		k=4;//�ڶ���ѭ��׼��

		}

		for(k=0,jisuan=0;k < 8; k++)
		{
			jisuan=jisuan+temp[k]*pow((float)2,k);
			temp[k]=0;//�������
		}


		printf("%d",jisuan);


	}



    printf("\n");
//	printf("%s\n",shuru1);
    system("pause");
    return 0;
}

/*����ʱ�䣺 2016-08-07 20:03:36
  �������⣺
  ���Ĺ��ܣ�������������ڸ�λ���� ÿ����λת����2�����������temp[8]�������� �ٰ�2������ת����10������ ��ӡ���� �ڶ���һ��2λ����
*/