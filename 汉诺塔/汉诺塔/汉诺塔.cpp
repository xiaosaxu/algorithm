#include<stdio.h>
#include<stdlib.h>

int count = 1;//��¼�ƶ�����

void move(int n, char from, char to)
{
	printf("��%d�Σ��ѵ� %d �����Ӵ� %c �ƶ��� %c\n", count++, n, from, to);
}

void hanuo(int num, char from, char depend_on, char to)
{
	if(1==num)
	{
		move(1, from, to);
	}
	else
	{
		hanuo(num-1, from, to, depend_on);
		move(num,from,to);
		hanuo(num-1,depend_on, from, to);
	}

}
int main(void)
{

	int num=1;

	while(num!=0)
	{
		count=1;

		scanf("%d",&num);

		printf("���������ð�%d������ ��A�ƶ���C \n���� 0 ��������\n",num);
		
		hanuo(num, 'A' ,'B' ,'C');
	}

	system("pause");

	return 0;

}
/*����ʱ�䣺 2016-08-10 10:42:13
  �������⣺
  ���Ĺ��ܣ�1.ʹ��ȫ�ֱ���count�洢�ܴ���  2.����ֻ��һ������ʱ��һ���� �����������ͬ
*/