/*��ʼʱ�䣺 2016-07-31 23:46:17
ʵ�ֹ��ܣ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

void print()
{
	char a;
	scanf("%c", &a);
	if(a!= '#')
		print();
	if(a!= '#') //ע�⺯������֮������￪ʼִ�� ��ӡ֮ǰ����
		printf("%c ",a);

}

int main(void)
{
    
	print();

    system("pause");
    return 0;
}

/*����ʱ�䣺 2016-07-31 23:49:50
  �������⣺
  ���Ĺ��ܣ�
*/