/*��ʼʱ�䣺 2016-07-14 20:38:30
ʵ�ֹ��ܣ�
��дһ�����򣬽������ַ����е��ַ������¹�������
����1��Ӣ����ĸ��A��Z���У������ִ�Сд��
      �磬���룺Type �����epTy
����2��ͬһ��Ӣ����ĸ�Ĵ�Сдͬʱ����ʱ����������˳�����С�
    �磬���룺BabA �����aABb
����3����Ӣ����ĸ�������ַ�����ԭ����λ�á�
    �磬���룺By?e �����Be?y
������
    ���룺
   A Famous Saying: Much Ado About Nothing(2012/8).
    �����
   A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int iszimu(char zifu)
{
	if((zifu>='a'&&zifu<='z')||(zifu>='A'&&zifu<='Z'))
		return 1;
	else
		return 0;
}

int comp(char a,char b)
{
	if(a>='A'&&a<='Z')
		a+='a'-'A';

	if(b>='A'&&b<='Z')
		b+='a'-'A';

	return a<b;
}

int main(void)
{
	char shuru1[200]={0},tiqu1[200]={0};
	char *shuru=shuru1;
	char *tiqu=tiqu1;
	int i,j=0;

	gets(shuru);

	for(i=0;i<strlen(shuru);i++)
		if(iszimu(shuru[i]))
			tiqu[j++]=shuru[i];
	tiqu[j]='\0';

	stable_sort(tiqu,tiqu+strlen(tiqu),comp);//��ȡ�������

	for(i=0,j=0;i<strlen(tiqu);i++)
	{
			while(0==iszimu(shuru[j]))
				j++;
			shuru[j++]=tiqu[i];
	}
	printf("%s\n",tiqu);
	printf("%s\n",shuru);

    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-07-14 21:07:02
  �������⣺
  ���Ĺ��ܣ��Ȱ���ĸ��ԭ���������ַ�������ȡ���� �������� �ٰ��ź�˳����ַ��� ���ǵ�ԭ��������ַ����� �������ַ�������
*/