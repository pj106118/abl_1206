//��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int pow(int k)
{
	int a = 5;
	if (k == 1)
	{
		return a;
	}
	return a * pow(k - 1);
}
int main()
{
	int k;
	printf("������һ��ָ����\n");
	scanf("%d", &k);
	printf("%d\n",pow(k));
	system("pause");
	return 0;
}
