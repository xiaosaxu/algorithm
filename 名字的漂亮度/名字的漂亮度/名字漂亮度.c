#include<stdio.h>
#include<string.h>

#define MAX 100

int CaulatBeauty(char *name);

int main(void)
{
	char ShuRu[MAX][MAX];

	char ab[100];
	int Num=0,Num2;
	int i=0,j;


	scanf("%d",&Num);// 空格 在输入界面是截断符号
	Num2=Num;
	while(Num>0)
	{
	scanf("%s",ShuRu[i++]);		
	Num--;
	}
	
	for(i=0;i<Num2;i++)
	printf("%d\n",CaulatBeauty(ShuRu[i]));

	

/*
	for(j=0;j<i;j++)
		printf("%s\n",ShuRu[j]);

		system("pause");
*/

}

int CaulatBeauty(char *name)
{
	int Beauty=0,len,i,j,temp,max=26;
	int a[100]={0};

	len=strlen(name);
	for(i=0;i<len;i++)
	{
		if(name[i]>'Z')//小写转大写
			name[i]-=32;

		a[name[i]]++;//统计重复字符
	}

	for(i=0;i<100;i++)
		for(j=1;j<100-i;j++)
			if(a[j-1]<a[j])
			{
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}

	for(i=0;i<27;i++)
	{
		Beauty+=(a[i]*max);
		max--;
	}

	return Beauty;
}