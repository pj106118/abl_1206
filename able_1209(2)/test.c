#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Isleap(int a)
{
	
	if (a % 4 != 0)
		return -1;
	else
		if (a % 100 != 0)
			return 1;
		else
		{
			if (a % 400 == 0)
				return 1;
			else
				return -1;
		}
	
}
void main()
{
	int a;
	printf("������һ������:");
	scanf("%d", &a);
	int temp = Isleap(a);
	if (temp == 1)
		printf("�����꣡");
	if (temp == -1)
		printf("�������꣡");
	system("pause");
}