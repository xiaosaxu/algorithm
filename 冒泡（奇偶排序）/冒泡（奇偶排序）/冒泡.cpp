/*开始时间： 2016-08-15 17:08:54
实现功能：
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

int fanzhuan(int data)
{
	int erjz[4]={0};
	int i=0;
	int temp=0;
	while(data)
	{
		erjz[i++] = data%2;
		data /= 2;
	}
	for(i=0; i<4; i++)
		temp=temp*2+erjz[i];
	
	if(temp<=9 && temp>=0)
		temp=temp+'0';
	else 
		if(temp<=15 && temp>= 10)
			temp=temp-10+'A';
		else
			temp=temp+'0';
	
		
	return temp;

}

void chuli(char & zifu)
{
	int temp=0;
	if(zifu<='9'&&zifu>='0')
	{
		temp = zifu - '0';
		zifu = fanzhuan(temp);
	}
	else
	if(zifu<='f'&&zifu>='a')
	{
		temp = zifu - 'a' + 10;
		zifu = fanzhuan(temp);
	}
	else
	if(zifu<='F'&&zifu>='A')
	{
		temp = zifu - 'A' + 10;
		zifu = fanzhuan(temp);
	}


}

int main(void)
{
	
	char shuru1[1000]={0};
	char shuru[1000]={0};

	scanf("%s",shuru);
	scanf("%s",shuru1);

	strcat(shuru,shuru1);

	int len=strlen(shuru);

//	printf("%s\n",shuru);

	int i=0,j=0;
	char temp;

	for(i=0; i<len; i++)
		for(j=2; j<len-i; j+=2)
		if(shuru[j-2]>shuru[j])//偶数排序
		{
			temp=shuru[j-2];
			shuru[j-2]=shuru[j];
			shuru[j]=temp;
		}
	
//	printf("%s\n",shuru);

	for(i=0; i<len; i++)
		for(j=3; j<len-i; j+=2)
		if(shuru[j-2]>shuru[j])//奇数排序
		{
			temp=shuru[j-2];
			shuru[j-2]=shuru[j];
			shuru[j]=temp;
		}
	
//	printf("%s\n",shuru);

	for(i=0; i<strlen(shuru); i++)
		chuli(shuru[i]);


//冒泡全排序
	for(i=0; i<len; i++)
		for(j=1; j<len-i; j++)
			if(shuru[j-1]<shuru[j])
			{
				temp=shuru[j-1];
				shuru[j-1]=shuru[j];
				shuru[j]=temp;
			}

	printf("%s\n",shuru);





	system("pause");
}

/*结束时间： 2016-08-15 17:34:47
  存在问题：
  核心功能：完成 奇偶冒泡 和完全排序（第一层可以不变）
*/