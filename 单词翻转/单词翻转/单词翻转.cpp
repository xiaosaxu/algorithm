/*��ʼʱ�䣺 2016-07-11 21:03:09
ʵ�ֹ��ܣ����ʷ�ת
ͨ������Ӣ�ľ��ӣ���ÿ�����ʷ�������������˳�򲻱䡣��26����ĸ�ҷǱ����ŵ�������ɱ�ʶ���ʽ�����
�����Ű���,.!?

��������	Hello, I need an apple.
�������	olleH, I deen na elppa.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

void swap(char shuru[],int st,int ed)
{
	char temp;
	while(st<ed)
	{
		//�ж������������
		while(shuru[st]==','||shuru[st]=='.'||shuru[st]=='!'||shuru[st]=='?'||shuru[st]==' ')//�������ֻ���Ҳ��ʵ�ֱ�������λ�ò���ķ�ת
			st++;
		while(shuru[ed]==','||shuru[ed]=='.'||shuru[ed]=='!'||shuru[ed]=='?'||shuru[ed]==' ')
			ed--;
		if(st<ed)//��ֹ����ֻ��һ������ ����Ҫ����
		{
		temp=shuru[st];
		shuru[st]=shuru[ed];
		shuru[ed]=temp;

		st++;
		ed--;
		}
	}
}

int main(void)
{
	char shuru1[100]={0};
    char *shuru=shuru1;
	int i=0,j=0,k=0,kge[100]={0};

	gets(shuru);

	
	j=1;//��һ��Ԫ��λ��
	for(i=0;i<strlen(shuru);i++)
		if(shuru[i]==' ')
			kge[j++]=i;
	
	kge[j]=strlen(shuru)-1;//���һ��Ԫ��λ�� ����ʹ���˼�һ

	for(k=1;k<=j;k++)//��ÿ�����ʽ��н���
		swap(shuru,kge[k-1],kge[k]);

	for(i=0;i<strlen(shuru);i++)
		printf("%c",shuru[i]);
	printf("\n");

    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-07-11 21:47:31
  �������⣺strlen()��Ľ����ʵ��ֵ��1�� �����ַ������������������һ������ǰ�� ʹ�����һ�����ʱ��ض� Ϊʲô

      ���ͣ�strlen()���ص���ʵ���ַ������ַ��ĸ��� ���һ���ַ��� "I" ����I��һ���ַ������ôstrlen()����1������1ȥ���ʸ��ַ����������ʱ��ͻᵼ�·��ʵ��ַ�����β��־ 
	        ��ȷ�ķ���Ӧ���� shuru[0] ���������ѭ������ʹ�õ�ʱ���� <strlen(shuru),��û�е��ڣ� 



  ���Ĺ��ܣ�ʹ��ͷβ����ָ�� ���н��� ������λ
  while(shuru[st]==','||shuru[st]=='.'||shuru[st]=='!'||shuru[st]=='?'||shuru[st]==' ')
			st++;
			ԭ��ʹ��if����ֻ�б�һ�� ������������������ ����, �����Ÿ��ո���һ����׼ȷ����λ

			ʹ��kge[]������ÿ�����ʵĽ���λ��
*/