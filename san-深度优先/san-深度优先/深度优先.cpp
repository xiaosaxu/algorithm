/*��ʼʱ�䣺 2016-09-06 14:37:35
ʵ�ֹ��ܣ�
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int ditu[50][50]={0};
int book[50][50]={0};
int hang = 0, lie = 0;
int i = 0,j = 0,k = 0; 
int stx=0,sty=0,edx=0,edy=0;

int next[4][2]={1,0, 0,1, -1,0, 0,-1};//�ֱ�Ϊ �� �� �� ��
int minstep = 99;


void DFS(int x, int y, int step)
{
	if(x == edx && y == edy)
	{
		if(step < minstep)
			minstep = step;//�������ͨ���ݹ����ȼ�¼�߹��Ĳ��� �������ͨ��ÿһ��Ĵ��� �ڽṹ���������������

		return ;
	}
	else
	{
		for(int i=0; i<4; i++)
		{
			int next_x = x + next[i][0];//ע��������Ҫ�½���ʱ������ ÿ��ѭ��Ҫ����֮ǰ��ֵ�ı������С
			int next_y = y + next[i][1];

			if(next_x < 1 || next_x > lie || next_y < 1 || next_y > hang)
				continue;

			if(book[next_x][next_y] == 0 && ditu[next_x][next_y] == 0)//0 ��ʾδ���� ����
			{
				book[next_x][next_y] = 1;
				DFS(next_x, next_y,step+1 );
				book[next_x][next_y] = 0;
			}

		}
	}
}

int main(void)
{


	scanf("%d %d",&hang,&lie);

	for(i=1; i<=hang; i++)
		for(j=1; j<=lie; j++)
			scanf("%d",&ditu[i][j]);//����Ĵ���Ҳ�ǱȽ���Ҫ��

	scanf("%d %d %d %d",&stx,&sty,&edx,&edy);//�����������

	book[stx][sty] = 1;//������

	DFS(stx, sty, 0);//����ʼ����� ����step��0 

	printf("%d\n",minstep);


	system("pause");

	return 0;
				
		
}

/*����ʱ�䣺 2016-09-06 15:14:05
  �������⣺
  ���Ĺ��ܣ�
*/