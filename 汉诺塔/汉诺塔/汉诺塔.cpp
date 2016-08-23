#include<stdio.h>
#include<stdlib.h>

int count = 1;//记录移动次数

void move(int n, char from, char to)
{
	printf("第%d次，把第 %d 个盘子从 %c 移动到 %c\n", count++, n, from, to);
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

		printf("本程序作用把%d个盘子 从A移动到C \n输入 0 结束程序\n",num);
		
		hanuo(num, 'A' ,'B' ,'C');
	}

	system("pause");

	return 0;

}
/*结束时间： 2016-08-10 10:42:13
  存在问题：
  核心功能：1.使用全局变量count存储总次数  2.除了只有一个盘子时不一样外 其他情况都相同
*/