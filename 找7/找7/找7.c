#include<stdio.h>
#include<string.h>
int sum=0;
int findseven(int shuzi);

int main(void)
{
	int target=0,i;
	scanf("%d",&target);

	for(i=1;i<=target;i++)
	{
		if(i%7==0)//注意 0%某个数都等于0 导致会把0计算在内 从1循环排除0
		{
			sum++;
			//printf("%d ",i);
			continue;
		}
		else
		{
			if(findseven(i)==1)
			{
				sum++;
				//printf("%d ",i);
			}

		}
	}

	printf("%d\n",sum);

	//system("pause");
	return 0;
}

int findseven(int shuzi)
{
	char aa[10]={0};
	char * bb=aa;
	int len=0,i;

	sprintf(bb,"%d",shuzi);

	len=strlen(bb);

	for(i=0;i<len;i++)
		if(bb[i]=='7')
			return 1;
		/*else
			return 0;*///导致只比较一次
	return 0;


}