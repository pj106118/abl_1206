//�ݹ���n�Ľ׳�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int fact(int a)
{
	int ret = 1;
	if (a > 1)
	{
		ret = a * fact(a - 1);
	}
	if (a == 1)
		ret = 1;
	 return ret;
}
int main()
{
	int a = 0;
	printf("��������Ҫ��Ľ׳�����\n");
	scanf("%d", &a);
	printf("%d \n",fact(a));
	system("pause");
	return 0;
}