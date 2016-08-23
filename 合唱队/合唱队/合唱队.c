#include<stdio.h>

int main(void)
{

	int renshu,shengao[500]={0};
	int currentlen=0,len=0,end=0,currentlen2=0,len2=0,end2=0;
	int i,j=0,book[500]={0};

	scanf("%d",&renshu);
	for(i=0;i<renshu;i++)
		scanf("%d",&shengao[i]);
	
	for(i=1;i<renshu;i++)
	{
		if(shengao[i-1]<shengao[i])
		{
			currentlen++;			
		}
		else
			currentlen=0;
				
		if(currentlen>len)// i<renshu/2 防止出现增长序列在最后面的的问题   &&(i<renshu/2)
		{
			len=currentlen;
			end=i;
		}



//*****************递减统计**********************
		if(shengao[i-1]>shengao[i])
		{
			currentlen2++;			
		}
		else
			currentlen2=0;
				
		if(currentlen2>=len2)//加上=条件 是吧 复合的人员往后面移动
		{
			len2=currentlen2;
			end2=i;
		}
			
		
	}


	len++;
	len2++;//修改偏差

	for(i=end-len+1;i<end+1;i++)
	{
		//printf("%d ",shengao[i]);
		book[i]=1;//进行统计符合的人数
	}

	for(i=end2-len2+1;i<end2+1;i++)
	{
	//	printf("%d ",shengao[i]);
		book[i]=1;//进行统计符合的人数
	}

	for(i=0;i<500;i++)
		if(book[i]==1)
			j++;

	printf("%d\n",renshu-j);



	//system("pause");




	return 0;
}