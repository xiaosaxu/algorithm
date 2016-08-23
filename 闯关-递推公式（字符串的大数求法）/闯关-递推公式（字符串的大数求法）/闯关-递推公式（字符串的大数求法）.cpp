/*开始时间： 2016-07-14 16:35:45
实现功能：

已知一个递推公式A[N+1] = A[N] * 2 + 2，且A[1] = 2，求A[N]的值
 
详细描述：
接口说明
原型：
voidCalculateAN(unsigned n, char *pOutRes)
输入参数：
unsigned n 题目描述中的N
输出参数：
char *pOutRes A[N]的值。因为当n较大时，A[N]的值会很大，因此结果用一个字符串表示。该字符串的内存空间由调用者保证，内存大小足够长。
返回值：
void
限制：
0< n <65535
举例：
A[1] = 2, A[5] = 62, A[8] = 510

内存限制	128MByte
输入	
输入一个整数
输出	
输出得到的值
样例输入	1
样例输出	2

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
	for(i=1;i<index;i++)//做这么多次
	{
		for(j=99;shuzi[j]!='-';j--)//每次需要做这么多
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
					while((shuzi[before]-'0')>=10&&shuzi[before]!='-')//循环处理进位
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
/*结束时间： 2016-07-14 17:19:30
  存在问题：
  核心功能：
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