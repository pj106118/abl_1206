#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num1;
	int num2 = 123456;
	int i;
	for ( i = 1;i <= 3; ++i )
	{
		printf("�������������룺\n");
		scanf("%d", &num1);
		if (num1 == num2)
		{
			break;
		}
		else
			printf("�������,����������!\n");
	}
	if (i <= 3)
		printf("��½�ɹ���\n");
	else
		printf("���������δ��������µ�¼��\n");
	system("pause");
	return 0;
}