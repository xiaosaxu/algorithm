/*��ʼʱ�䣺 2016-08-14 14:11:49
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int mymax(int a,int b )
{
	return (a>b?a:b); //����ʹ�����Զ��庯�� �����ֵ
}

int main(void)
{
	
	int money=0;
	int num=0;
	int k=0;

	int goodsinfo[70][3]={0};

	int Value[70][3500]={0};//����������СҪ��ʵ�ʵĴ�

	int i=0,j=0;

	scanf("%d %d", &money,&num);
	money/=10;//���е�Ǯ��Ҫ����10

	for(i=1; i<=num; i++)
	{
		scanf("%d %d %d",&goodsinfo[i][0],&goodsinfo[i][1],&goodsinfo[i][2]);//�۸� ��Ҫ��
		//��Ϊ�ڶ�̬�滮��ѭ���е��±��1��ʼ�� ��� �洢��Ʒ��Ϣ��������±�ҲҪ��1��ʼ ���������� ������С�ڵ���num��
	}
	for(i=1; i<=num; i++)
	{
		goodsinfo[i][0]/=10;//ͳһȫ������10
	}

	for(i=1; i<=money; i++)//Ǯ �ж���Ǯ��Ҫѭ�����ٴ� ʵ��ʹ��ȡ��meoneyֵ�� ����֮ǰ���������ĵĴ�СҪ��ʵ�ʵĴ�һЩ
		for(j=1; j<=num; j++)//�������� �ж��ٻ���ҲҪѭ�����ٴ�
		{
			if(goodsinfo[j][2]==0)//˵��������
			{
				if(i>=goodsinfo[j][0])
				{
					Value[j][i]=mymax(Value[j-1][i],Value[j-1][i-goodsinfo[j][0]]+goodsinfo[j][0]*goodsinfo[j][1]);//��Ϊ�� ���� ����
				}
				else
				{
					Value[j][i]=Value[j-1][i];//��ʾ�Ų���ȥ ������һ��ֵ
				}
			}

			else//�Ӽ�
			{
				k=goodsinfo[j][2];//�����ı��

				if(i>=goodsinfo[j][0]+goodsinfo[k][0])
				{
					Value[j][i]=mymax(Value[j-1][i],Value[j-1][i-goodsinfo[j][0]-goodsinfo[k][0]]+goodsinfo[j][0]*goodsinfo[j][1]+goodsinfo[k][0]*goodsinfo[k][1]);//��Ϊ�� ���� ����
				}
				else
				{
					Value[j][i]=Value[j-1][i];//��ʾ�Ų���ȥ ������һ��ֵ
				}
			}
		}

		printf("%d\n", Value[num][money]*10);//֮ǰ������Ҫ�ǵóɻ���
	

    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-08-14 14:54:26
  �������⣺
  ���Ĺ��ܣ� ֻ�͵�ǰ���й� �������޹� ��һ�����ǰѵ�һ���ܷŽ�ȥ��ֵ�Ž�ȥ ע��ѭ����С��ϵ�� ��1��ʼ
			��̬�滮����˼����Ҫ��� ���ݽṹ�ı�� ����Ľṹ������Ҫ���ǵ�
*/