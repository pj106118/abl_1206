#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int Isprime()
{
	int j, t, n;
	printf("������һ������\n");
	scanf("%d", &n);                   //����һ�����ж��Ƿ�������
	t = sqrt(n);
	for (j = 2; j <= t; j++)
		if (n%j == 0)
			break;
	if (j > t)
		return 1;
	else
		return -1;
}
int main()
{
	int num = Isprime();
	if (num == 1)
		printf("���������������");
	else
		printf("������Ĳ���������");
	system("pause");
	return 0;
}
