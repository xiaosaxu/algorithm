/*��ʼʱ�䣺 2016-09-06 21:21:23
ʵ�ֹ��ܣ�
*/
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int dianshu,bianshu;
	int ditu[50][50] = {0};//ע�⸳ֵ���̲���
	int a,b,c;
	int i,j,k;
	scanf("%d %d",&dianshu,&bianshu);

	for(i=1; i<=bianshu; i++)
		for(j=1; j<=bianshu; j++)
		{
			if(i==j) 
				ditu[i][j] = 0;
			else
				ditu[i][j] = 9999;

		}

	for(i=1;i<=bianshu;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		ditu[a][b] = c;
	}

	for(k = 1; k<=dianshu; k++)
		for(i=1; i<=dianshu; i++)
			for(j=1; j<=dianshu;j++)
				if(ditu[i][j] > ditu[i][k] + ditu[k][j])
					ditu[i][j] = ditu[i][k] + ditu[k][j];

	for(i=1; i <= dianshu; i++)
	{
		for(j=1; j <= dianshu; j++)
		{
			printf("%10d",ditu[i][j]);
		}
		printf("\n");

	}

	system("pause");
}
/*����ʱ�䣺 2016-09-06 21:44:32
  �������⣺
  ���Ĺ��ܣ�floyd �㷨������� ����������֮������·�� �ؼ���Ҫ���ٽ�������� ���ǵ������ ���±�1��ʼ
  ��ֹ�ڴ�Խ�� �����������ݱ����
*/