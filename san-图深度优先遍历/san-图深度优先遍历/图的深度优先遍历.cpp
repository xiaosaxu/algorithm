/*��ʼʱ�䣺 2016-09-06 19:38:35
ʵ�ֹ��ܣ��������֮����ͨ�Ľڵ� ��� ������ȱ����͹�����ȱ����Ľ��
*/

#include<stdio.h>
#include<stdlib.h>

	int ditu[50][50] = {0};
	int book[50] = {0};
	int dianshu = 0,bianshu = 0;
	int i,j,k;
	int a,b,c;

void DFS(int num, int step)
{
	printf("%d",num);
	if(step == dianshu)//ʵ������������ǿ��Ƶݹ���� �������ظ���֤��ȵ��ڵ����Ǳ�����
		return ;
	else
	{
		for(int i=1; i<=dianshu; i++)//ע�� �ݹ������ѭ������һ���Ǿֲ����� �����ܵݹ� �������
		{
			if(ditu[num][i] == 1 && book[i] == 0)
			{
				book[i] = 1;
				DFS(i, step+1);
			}

		}
	}
}

int main(void)
{


	scanf("%d %d",&dianshu,&bianshu);

	for(i=1; i<=bianshu; i++)
	{
		scanf("%d %d",&a,&b);
		ditu[a][b] = 1;
		ditu[b][a] = 1;
	}
	for(i=1; i<=dianshu; i++)
		ditu[i][i] = 0;

	book[1] = 1;
	DFS(1,0);

	system("pause");
}

/*����ʱ�䣺 2016-09-06 20:22:41
  �������⣺
  ���Ĺ��ܣ� �ݹ�ʱֱ���õ����Ž��еݹ�
			ditu[num][i] == 1 && book[i] == 0 �����Ϊ��ά�������жϱ�׼ ���Ƿ�����  �յ��Ǹĵ� ���Ƿ���book������
*/