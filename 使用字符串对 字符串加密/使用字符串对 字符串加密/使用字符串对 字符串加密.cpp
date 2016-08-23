// 使用字符串对 字符串加密.cpp : 定义控制台应用程序的入口点。
//

/*
有一种技巧可以对数据进行加密，它使用一个单词作为它的密匙。下面是它的工作原理：首先，选择一个单词作为密匙，如TRAILBLAZERS。如果单词中包含有重复的字母，只保留第1个，其余几个丢弃。现在，修改过的那个单词死于字母表的下面，如下所示：
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
T R A I L B Z E S C D F G H J K M N O P Q U V W X Y
上面其他用字母表中剩余的字母填充完整。在对信息进行加密时，信息中的每个字母被固定于顶上那行，并用下面那行的对应字母一一取代原文的字母(字母字符的大小写状态应该保留)。因此，使用这个密匙，Attack AT DAWN(黎明时攻击)就会被加密为Tpptad TP ITVH。
请实现下述接口，通过指定的密匙和明文得到密文。
详细描述：
接口说明
原型：
voidencrypt(char * key,char * data,char * encrypt);
输入参数：
    char * key：密匙
    char * data：明文
输出参数：
    char * encrypt：密文
返回值：
        void


*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{

	char a[200]={0},b[200]={0},book[200]={0};
	char key[20]={0},data[20]={0};
	int i=0,j=0;

	for(i='A';i<='Z';i++)//初始化a
		a[i]=i;


	scanf("%s",key);
	scanf("%s",data);



	for(i=0;i<strlen(key);i++)
	{
		if(key[i]>'Z')//小写转大写
			key[i]-=('a'-'A');
	}


	for(i=0;i<strlen(key);i++)
		if(book[key[i]]==0)
		{
			b[j++]=key[i];
			book[key[i]]=1;
		}
	b[j]='\0';//第一步完成


	for(i=strlen(b)-1;i<26;i++)//一共26个英文字母
	{
		for(j='A';j<='Z';j++)
		if(book[key[j]]==0)
		{
			book[key[j]]=1;
			b[i]=j;
			break;//当前元素赋值完成 退出当前的循环 进入下一个元素判断
		}
	}
	
	printf("%s",b);

	printf("%s",data);


	system("pause");
	return 0;
}

