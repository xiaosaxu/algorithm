/*��ʼʱ�䣺 2016-08-14 19:47:23
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
    
	char shuru1[100]={0};
	char *shuru=shuru1;
	int modNumber=0;

	scanf("%s %d",shuru, &modNumber);

	long sum = 0;
    //����14689�����ɶ���ʽ��ӵĺͣ���1*10^5+4*10^4+6*10^3+8*10^2+9*10^1��ÿһ���������X,Y,Z
    ///���һЩģ��������������ǣ����磬�Զ�����ֵ��������ģ���ȶ��м䲿�ֽ����ģ����Ӻ����������ģ�Ľ����һ����
    //��  (X+Y+Z)modP =((X+Y)modP+ Z)modP = ((XmodP +Y)modP+Z)modP 
    //�ɴ˿����Ƴ�����Ĵ��룺
    for (int i = 0; i < strlen(shuru); ++i)
    {

        sum = sum*10 + shuru[i]-'0';//����Ҫ��ÿ���ַ���ASCII���ȥ48��Ϊ����
       
        sum %= modNumber;
        printf("������%ld\n", sum);
    }


    system("pause");
    return 0;
}