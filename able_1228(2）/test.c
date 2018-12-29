//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int DigitSum(int n)
{
	if (n > 0)
	{
		return n % 10 + DigitSum(n / 10);
	}
	return 0;
}
int main()
{
	int n = 0;
	printf("请输入一个非负整数：\n");
	scanf("%d", &n);
	printf("%d\n", DigitSum(n));
	system("pause");
	return 0;
}