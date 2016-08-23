/*开始时间： 2016-08-10 11:39:06
实现功能：八皇后
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int queen[8]={0};//用queen存放每一列皇后所在行的位置 0表示没有存放 非零表示皇后的位置
int num=0;

int safe(int * queen,int current_lie)
{
	for(int i=0;i<current_lie; i++)
	{
		if(queen[i]==queen[current_lie])	//表示和之前有一行相同
			return 0;


		if(abs(queen[i] - queen[current_lie])==abs(i-current_lie))
			return 0;
	}

	return 1;
}

//皇后的所有位置采用递归遍历所有的可能位置 类似于深度优先的全排列求解、
void Queen( int lie)
{
	if(lie==8)//这个起始位置是0 到最后7 为止 最后一个递归编程8 结束递归
	{
		num++;
		return ;
	}

	for(int i=2; i <= 9; i++)//实际上i表示的是第几列 可以从1到8 也可以2到9 为什么不能0到7？ 因为原来的数组里面默认的元素就是0 会导致在一行了的错误判断
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

/*结束时间： 2016-08-11 10:49:18
  存在问题：
  核心功能：类似于DFS的递归
*/