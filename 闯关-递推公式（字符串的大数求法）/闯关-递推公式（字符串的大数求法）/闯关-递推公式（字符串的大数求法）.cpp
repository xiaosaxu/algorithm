/*��ʼʱ�䣺 2016-07-14 16:35:45
ʵ�ֹ��ܣ�

��֪һ�����ƹ�ʽA[N+1] = A[N] * 2 + 2����A[1] = 2����A[N]��ֵ
 
��ϸ������
�ӿ�˵��
ԭ�ͣ�
voidCalculateAN(unsigned n, char *pOutRes)
���������
unsigned n ��Ŀ�����е�N
���������
char *pOutRes A[N]��ֵ����Ϊ��n�ϴ�ʱ��A[N]��ֵ��ܴ���˽����һ���ַ�����ʾ�����ַ������ڴ�ռ��ɵ����߱�֤���ڴ��С�㹻����
����ֵ��
void
���ƣ�
0< n <65535
������
A[1] = 2, A[5] = 62, A[8] = 510

�ڴ�����	128MByte
����	
����һ������
���	
����õ���ֵ
��������	1
�������	2

*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

char shuzi[100]={0};
char *shuzi2=shuzi;

void jisuan(int index)
{
	int i=0,j=0;
	for(i=1;i<index;i++)//����ô���
	{
		for(j=99;shuzi[j]!='-';j--)//ÿ����Ҫ����ô��
		{
			int temp=2*(shuzi[j]-'0')+2;
			if(temp<10)
				shuzi[j]=temp+'0';
			else
			{
				shuzi[j]=temp%10;
				if(shuzi[j]!='-')		
				{
					shuzi[j-1]+=(temp/10+'0');
					int before=j-1;
					while((shuzi[before]-'0')>=10&&shuzi[before]!='-')//ѭ�������λ
					{
						shuzi[before]='0';
						if(shuzi[before-1]!='-')
							shuzi[before-1]++;
						else
							shuzi[before-1]='1';
						before--;
					}

				}
				else
					shuzi[j-1]='1';

			}
		}
	}
}

int main(void)
{


	int i=0,index=0;

	for(i=0;i<100;i++)
		shuzi[i]='-';

	shuzi[99]='2';
while(1)
{
	scanf("%d",&index);

	jisuan(index);

for(i=0;i<100;i++)
{
	if(shuzi[i]!='-')
	printf("%c ",shuzi[i]);
}

}
    system("pause");
    return 0;
}
/*����ʱ�䣺 2016-07-14 17:19:30
  �������⣺
  ���Ĺ��ܣ�
*/
//http://blog.csdn.net/yiqiwangxi/article/details/48057001
#include<iostream>
#include<string>
using namespace std;
string add(string s1,string s2)  
{  
    string s3;  
    int len_short,len_long;  
    if(s1.size()>s2.size())  
    {  
        len_short=s2.size();  
        len_long=s1.size();  
        s3=s1;  
    }  
    else  
    {  
        len_short=s1.size();  
        len_long=s2.size();  
        s3=s2;  
    }  
    int flag=0;  
    int tmp;  
    for(int i=1;i<=len_short;i++)  
    {  
        tmp=s1[s1.size()-i]-'0'+s2[s2.size()-i]-'0'+flag;  
        if(tmp>9)  
        {  
            s3[s3.size()-i]=tmp-10+'0';  
            flag=1;  
        }  
        else  
        {  
            s3[s3.size()-i]=tmp+'0';  
            flag=0;  
        }  
    }  
      
    for(int i=0;i<s3.size()-len_short;i++)  
    {  
        tmp=s3[i]-'0'+flag;  
        if(tmp>9)  
        {  
            s3[i]=tmp-10+'0';  
            flag=1;  
        }  
        else  
            flag=0;  
    }  
    if(flag==1)  
        s3="1"+s3;  
    return s3;  
}  
string CalculateAN(unsigned int n)
{
	if(n==1)
		return "2";
	string s=add(CalculateAN(n-1),"1");
	return add(s,s);
}
int main()
{
	int n;
	cin>>n;
	cout<<CalculateAN(n);
	system("pause");
	return 0;
}