/*��ʼʱ�䣺 2016-07-18 17:14:13
ʵ�ֹ��ܣ�
����һ��Ӣ���ı����ó���ͳ�Ƴ���Ƶ����ߺ͵ڶ��ߵ��������ʡ�
 
����������
��1��Ӣ���ı��н������������ַ����ո�( )��Ӣ�Ķ���(,)��Ӣ�ľ��(.)��Ӣ�Ĵ�Сд��ĸ��a-z��A-Z����
��2������֮��ķָ��������������֣��ո�( )��Ӣ�Ķ���(,)��Ӣ�ľ��(.)��
��3������Сд��ͬ�ĵ�����ͬһ�����ʣ�
��4�����ÿ����������ʳ��ִ�����ͬ�������
��5�����صĵ���ͳһ��Сд��ĸ���أ�

���磺
�����ַ���"Hello world, i said hello world to the world"�����"world,i"��
�����ַ���"Somebody like somebody, i do not like it"�����"somebody,i"��

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct danci
{
	char * word;
	int cishu;
	int countflag;
}tongji;

tongji AllDanCi[400]={0};

int index=0;

void FenPei(char shuru[],int st,int ed)
{
	char temp;
	int i,tt=0;

	char *danci;
	

		//�ж������������
		while(shuru[st]==','||shuru[st]=='.'||shuru[st]==' ')//�������ֻ���Ҳ��ʵ�ֱ�������λ�ò���ķ�ת
			st++;
		while(shuru[ed]==','||shuru[ed]=='.'||shuru[ed]==' ')
			ed--;

		danci=(char *)malloc(ed-st+1+1);

			for(i=st;i<=ed;i++)
			{
				//printf("%c",shuru[i]);
				danci[tt++]=shuru[i];
			}
		danci[tt]='\0';

		AllDanCi[index].word=danci;

		//printf("%s",AllDanCi[index].word);
		index+=1;
		//printf("\n");
	
}



int cmp(tongji s1,tongji s2)
{
	if(s1.cishu>s2.cishu)
		return 1;
	else 
		return 0;
}

int main(void)
{
	

	char shuru1[1050]={0};
    char *shuru=shuru1;
	int i=0,j=0,k=0,kge[300]={0};

	gets(shuru);

	if(strlen(shuru)==0)
		return 0;
	j=1;//��һ��Ԫ��λ��
	for(i=0;i<strlen(shuru);i++)
	{
		if(shuru[i]==' ')					//��ȡ�ո�
			kge[j++]=i;
		if(shuru[i]>='A'&&shuru[i]<='Z')	//��Сдת��
			shuru[i]=shuru[i]+('z'-'Z');
	}
	
	kge[j]=strlen(shuru)-1;//���һ��Ԫ��λ�� ����ʹ���˼�һ

	for(k=1;k<=j;k++)//��ÿ�����ʷŽ���Ӧ�Ľṹ����
		FenPei(shuru,kge[k-1],kge[k]);

   for(i=0;i<index;i++)//���ִ���ͳ��
   {
	   if(AllDanCi[i].countflag==1)
		   continue;
	   for(j=0;j<index;j++)
	   if(strcmp(AllDanCi[i].word,AllDanCi[j].word)==0)
	   {
			AllDanCi[i].cishu+=1;
			AllDanCi[j].countflag=1;

	   }

	//   printf("%s %d\n",AllDanCi[i].word,AllDanCi[i].cishu);

   }

  // printf("\n\n");
    stable_sort(AllDanCi,AllDanCi+index,cmp);//���ճ��ִ�������

    printf("%s,",AllDanCi[0].word);
	if(index>1)
    printf("%s\n",AllDanCi[1].word);
	else
    printf("%s\n",AllDanCi[0].word);



    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-07-18 18:53:38
  �������⣺
  ���Ĺ��ܣ�ʹ�ýṹ���ŵ��� �Լ�����ֵĴ��� ͳ��ʱʹ�ýṹ��ı�־λ��ֹ�ظ�ͳ�� 
*/