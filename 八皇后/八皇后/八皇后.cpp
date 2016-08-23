/*��ʼʱ�䣺 2016-08-10 11:39:06
ʵ�ֹ��ܣ��˻ʺ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int queen[8]={0};//��queen���ÿһ�лʺ������е�λ�� 0��ʾû�д�� �����ʾ�ʺ��λ��
int num=0;

int safe(int * queen,int current_lie)
{
	for(int i=0;i<current_lie; i++)
	{
		if(queen[i]==queen[current_lie])	//��ʾ��֮ǰ��һ����ͬ
			return 0;


		if(abs(queen[i] - queen[current_lie])==abs(i-current_lie))
			return 0;
	}

	return 1;
}

//�ʺ������λ�ò��õݹ�������еĿ���λ�� ������������ȵ�ȫ������⡢
void Queen( int lie)
{
	if(lie==8)//�����ʼλ����0 �����7 Ϊֹ ���һ���ݹ���8 �����ݹ�
	{
		num++;
		return ;
	}

	for(int i=2; i <= 9; i++)//ʵ����i��ʾ���ǵڼ��� ���Դ�1��8 Ҳ����2��9 Ϊʲô����0��7�� ��Ϊԭ������������Ĭ�ϵ�Ԫ�ؾ���0 �ᵼ����һ���˵Ĵ����ж�
	{
		queen[lie]=i;
		if(safe(&queen[0],lie))
			Queen(lie+1);
	}
}



int main(void)
{
    
	Queen(0);

	printf("%d\n",num);
    system("pause");
    return 0;
}

/*����ʱ�䣺 2016-08-11 10:49:18
  �������⣺
  ���Ĺ��ܣ�������DFS�ĵݹ�
*/