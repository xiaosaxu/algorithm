/*��ʼʱ�䣺 2016-08-15 14:32:18
ʵ�ֹ��ܣ�ʵ����DFS����ȫ���п����ɺ��� sort����  next_permutation() ����
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

int visit[100] = {0};
int pailie[100] = {0};
int fanwei = 0;

char shuru[30] = {0};
char jieguo[30] = {0};
int book[20] = {0};
int len=0;


void DFS(int deepth)
{
	if(deepth > fanwei)
	{
		for(int i=0; i<= fanwei ;i++)
		{
			printf("%d ",pailie[i]);	
		}
		printf("\n");
	}
	else
	{
		for(int i=0; i <= fanwei; i++)
			if(visit[i] == 0)
			{
				visit[i]=1;
				pailie[deepth]=i;
				DFS(deepth+1);
				visit[i]=0;
			}
	}
}

void DFS2(int deepth)
{
	if(deepth>=len)
	{
			printf("%s\n", jieguo);
	}
	else
	{
		for(int i=0; i<len; i++)//�ӱ��ÿ�����������ʹ�õ�
			if(book[i] == 0)
			{
				book[i] = 1;//ʵ������Ҫ���±���� ��λ ������λ�õ�Ԫ���ѱ�ʹ��

				jieguo[deepth] = shuru[i];
				DFS2(deepth+1);

				book[i] = 0;
			}
	}
}

int main(void)
{

int runflag=0;
printf("����1�������ֵ�ȫ���� �����ʽ ����N �����0��N����ȫ����\n����2�����ַ�����ȫ���� ����һ���ַ��� ������ַ�����ȫ����\n");
scanf("%d",&runflag);

if(runflag==1)
{
    scanf("%d",&fanwei);
	DFS(0);
}

if(runflag==2)
{
	gets(shuru);
	len=strlen(shuru);
	DFS2(0);
}

    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-08-15 15:34:23
  �������⣺
  ���Ĺ��ܣ�������� book���� �ݹ�����ı߽������ж� �ݹ�֮��Ҫbook�ظ�����
*/
