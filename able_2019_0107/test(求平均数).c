//��������ƽ������a+b)/2
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void everage(int* a, int* b)
{
	float num = 0;
	num = (*a + *b) / 2.0;
	printf("%f\n", num);
}

int main()
{
	int a = 0;
	int b = 0;
	printf("��������������\n");
	scanf("%d,%d", &a, &b);
	everage(&a,&b);
	system("pause");
	return 0;
}