/*��ʼʱ�䣺 2016-09-06 15:19:05
ʵ�ֹ��ܣ�
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
//
typedef struct pso_tag
{
	int x;
	int y;
	int step;
	int father;
}Postion;

int ditu[50][50] = {0};
int book[50][50] = {0};

Postion queue[2500] = {0};
int tail=1,head=1;

int stx=0, sty=0, edx=0, edy=0;
int hang=0, lie=0;
int i,j,k;

int next[4][2]={1,0, 0,1, -1,0, 0,-1};

int main(void)
{
	scanf("%d %d",&hang, &lie);

	for(i=1; i<=hang; i++)
		for(j=1; j<=lie; j++)
			scanf("%d",&ditu[i][j]);

	scanf("%d %d %d %d",&stx, &sty, &edx, &edy);

	queue[tail].x = stx;
	queue[tail].y = sty;
	queue[tail].step = 0;//��ʼ�����
	tail++;

	book[stx][sty] = 1;//�����

	while(head < tail)
	{
		for(i=0; i<4; i++)
		{
			int next_x = queue[head].x + next[i][0];
			int next_y = queue[head].y + next[i][1];

			if(next_x < 1 || next_x > lie || next_y < 1 || next_y > hang)//���Թ����� �����ж����� 4������ѭ�� ��ѭ����ĵ����Ч�Ժ�Ŀ���Խ����ж� 
				continue;
			if(book[next_x][next_y] == 0 && ditu[next_x][next_y] == 0)//��ͼ����Ҫ������
			{
				queue[tail].x = next_x;
				queue[tail].y = next_y;
				queue[tail].step = queue[head].step + 1;
				book[next_x][next_y] = 1;
				tail ++;//ע�������һ�� �����Լӻ����Լ��ı�����������ʱ��һ��Ҫ����������ķ�Χ ��Ϊ�ı�����һ֮��Ĭ�ϵ�ֵΪ 0 
			}

			if(next_x == edx && next_y == edy)
			{
				printf("%d\n",queue[tail-1].step);//��������Ҫ�� tail-1 һ��Ҫע���Լӱ�����ֵ
			}
		}

		head ++;
	}

	system("pause");
 
	return 0;

	
}

/*����ʱ�䣺 2016-09-06 19:03:12
  �������⣺
  ���Ĺ��ܣ����ڹ�������㷨 �������ɵ�ÿ��·����������һ�� ��������¼·�� ���ϼ���·�����ݸ��� ���ϱ���Ľڵ�  ˼·������ʹ�ýṹ�� ����
  ���·���ַ� ���ýṹ������帳ֵ
*/
