/*��ʼʱ�䣺 2016-08-15 09:47:18
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct danci_flag
{
	char data[1000];
	int flag;
}Danci;

int cmp(Danci a, Danci b)
{
	if(a.flag>b.flag)
		return 1;
	else
		if(a.flag < b.flag)
			return 0;
		else
			if(a.flag == b.flag)
				if(strcmp(a.data, b.data) < 0)
					return 1;
				else
					return 0;

}
int main(void)
{
	Danci danci[20]={0};
	Danci danci1[20]={0};
	char target[1000]={0};

	int num=0;
	int i=0;
	int number=0;
	int xiongdi=0;

	scanf("%d",&num);
	for(i=0; i<num; i++)
	{
		scanf("%s",danci[i].data);
	}

	for(i=0; i<num; i++)
		danci1[i]=danci[i];

		scanf("%s", target);
		scanf("%d", &number);



	for(i=0; i<num; i++)
		if(strcmp(danci[i].data,target)==0)
			danci[i].flag = 2;//��ʾ��ͬ

	for(i=0; i<num; i++)
		sort(danci[i].data , danci[i].data+strlen(danci[i].data));
 

	sort(target,target + strlen(target));

	for(i=0; i<num; i++)
		if(strcmp(danci[i].data,target)==0&&danci[i].flag != 2)
		{
			danci[i].flag = 3;//��ʾ�ֵܵ���
			xiongdi++;
		}

	for(i=0; i<num; i++)
		danci1[i].flag=danci[i].flag;

	sort(danci1,danci1+15,cmp);

	printf("%d\n", xiongdi);

	int temp=0;
	for(i=0; i<num; i++)
		if(danci1[i].flag == 3)
		{
			temp++;
			if(temp==number)
			{
				printf("%s\n",danci1[i].data);
				break;
			}
		}


    system("pause");
    return 0;
}

/*����ʱ�䣺 2016-08-15 10:19:37
  �������⣺
  ���Ĺ��ܣ� ����ʹ������������ �������״̬ ʹ���������ͬ��ĸ�ĵ��ʽ����˹�һ������   sort���Զ��������� ��һ��Ϊ������ ����Ҫ�±�� strcmp���Զ��ַ����� ����������
  ���бȽ� �������������е�ֵ  �ڽṹ����ʹ��������˷����ڴ��ʹ��
*/