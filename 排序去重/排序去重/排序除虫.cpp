/*��ʼʱ�䣺 2016-08-13 10:23:29
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    int total=0;
	int ID[1000]={0};//�����������������������


    while(scanf("%d",&total)!=EOF)
	{
  //ID=(int *)malloc(sizeof(int)*total);
	for(int i=0;i<1000;i++)//ÿ�γ�ʼ��
		ID[i]=-1;

    for(int i=0; i<total; i++)
        scanf("%d",&ID[i]);
    
//    for(int i=0; i<10; i++)
//	printf("%d\n",ID[i]);

    sort(ID,ID+1000);
    
	int i=0;
	while(ID[i]==-1)
		i++;
    printf("%d\n",ID[i]);

    for(int j=i+1; j<1000; j++)//��β�϶��������� һֱ����β�жϼ���
        if(ID[j]!=ID[j-1])
            printf("%d\n",ID[j]);
	}
        system("pause");
   
    return 0;
}

/*����ʱ�䣺 2016-08-13 11:17:23
  �������⣺�Ժ���Ҫ��***˼·***������� �ڲݸ�ֽ��д���� ��Ϊ�Ǽ������� �ڰ�***�߽�����***�����
  ���Ĺ��ܣ�
*/