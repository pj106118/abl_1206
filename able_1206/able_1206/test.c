#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int Menu()
{
printf("*********************\n");
printf("1.��ʼ��Ϸ\n");
printf("2.������Ϸ\n");
printf("*********************\n");
printf("����������ѡ��:\n");
int a = 0;
scanf("%d", &a);
return a;
}                            //��������Ϸ�Ĳ˵�

void game()
{
	
	int v = rand() % 100;   //ʹ�������ɵ��������0��99֮��
	while (1)
	{
		printf("������һ������(0-99):\n");
		int b = 0;
		scanf("%d", &b);
		if (b < v)              //�Ե������ɵ���������û���������ֽ��бȽ�
		{
			printf("���ˣ�");
		}
		else if (b > v)
		{
			printf("���ˣ�");
		}
		else
		{
			printf("�¶��ˣ�");
			break;
		}
	}
}
void main()
{
	srand(time(0));
	int a = Menu();	
	while (1)
	{
		if (a == 1)
		{                      //��ʼ��Ϸ
			game();
			break;
		}
		else if (a == 2)
		{            //��Ϸ����
			printf("��Ϸ������");
			break;
		}
		else
		{
			printf("�������");
			break;
		}
	}
	system("pause");
}