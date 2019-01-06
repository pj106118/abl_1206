//ɨ����Ϸ

#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define COLS 11         //����
#define ROWS 11         //����
#define COL (COLS-2)
#define ROW (ROWS-2) 
#define MAX 10         //�׵ĸ���

void menu()
{
	printf("*********************************\n");
	printf("*********1.��ʼ��Ϸ**************\n");
	printf("*********2.������Ϸ**************\n");
	printf("*********************************\n");
}


void init_board(char mine[ROWS][COLS], char set, int row, int col)//��ʼ�����̺���Ϊset
{
	memset(mine, set, row*col * sizeof(mine[0][0])); //memset������г�ʼ������ ������������Ϊ��
}	                                              //����������ʼ��Ŀ�꣬�ܹ���ʼ���ֽ�

void set_mine(char mine[ROWS][COLS])//������׺���
{
	int count = MAX;//���ü���������¼Ҫ�����׵ĸ���
	while (count>0)
	{
		int x = rand() % 9 + 1;     //����1��9���������
		int y = rand() % 9 + 1;
		if ((mine[x][y]) == '0')     //�ж�ͬһλ���Ƿ��ظ�����
		{
			mine[x][y] = '1';
			count--;      //ÿ�ɹ�����һ�ţ��������ͼ�һ
		}
	}
}

void display(char mine[ROWS][COLS], int row, int col)     //��ӡ���̺���
{
	int i = 0;
	int j = 0;
	printf("  ");       //�����ո�Ϊ��ʹ���룬һ�������кţ�һ����������
	for (i = 1; i <= row - 2; i++)         //��ӡ�к�
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row - 2; i++)      //�������������Ϣ
	{
		printf("%d ", i);
		for (j = 1; j <= col - 2; j++)
		{
			printf("%c ", mine[i][j]);//
		}
		printf("\n");
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)  //ͳ��������Χ����Ŀ�ĺ���
{
	return mine[x - 1][y - 1]
		+ mine[x][y - 1] + mine[x + 1][y - 1]
		+ mine[x + 1][y] + mine[x + 1][y + 1]
		+ mine[x][y + 1] + mine[x - 1][y + 1]
		+ mine[x - 1][y] - 8 * '0';  //���������д�ŵ����ַ�'0',��Χ��8�����֣�
	                                 //����-8*'0'���ܷ���������intֵ
}

enum Option //ö�٣����Ӵ���ɶ���
{
	EXIT,  //Ĭ��Ϊ0
	PLAY   //Ϊ1
};

void game()
{
	char mine[ROWS][COLS] = { 0 };//���׵�λ�ÿɳ�ʼ��Ϊ��
	char show[ROWS][COLS] = { 0 };//����һ����mineһ�������������ţ�������Χ�׵���Ŀ
	int x = 0;
	int y = 0;
	int win = 0;
	init_board(mine, '0', ROWS, COLS);//��ʼ������,��λ�÷���
	init_board(show, '*', ROWS, COLS);//��ʼ�����飬��λ�÷�*

	set_mine(mine);//����
	display(show, ROWS, COLS);//��ӡ����
	while (win<(ROW*COL - MAX)) //���׵ĸ���
	{
		printf("�������Ų����꣺>");
		scanf("%d%d", &x, &y);
		system("cls");
		if (((x >= 1) && (x <= ROWS - 2)) && ((y >= 1) && (y <= COLS - 2)))//�ж����������Ƿ���������
		{
			if (mine[x][y] == '1')
			{
				printf("�ܲ��ң��ȵ�����\n");
				break;
			}
			else    //ÿ����һ����ζ������һ����
			{

				int count = get_mine_count(mine, x, y);//ͨ���˺���ͳ��ָ��������Χ�м�����
				show[x][y] = count + '0';//Ϊ�˴�ӡ*�����԰�display������ӡ�����͸�Ϊ%c��ӡ���������ַ���-
				win++;
				display(show, ROWS, COLS);//-Ϊ�˰�����Ҳ�ܴ�ӡ����������+'0',�����ӡ����������Ϊ��ASCLL���ֵ
			}
		}
		else
		{
			printf("������������\n");

		}
	}
	if (win == ROW*COL - MAX)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
	}
	printf("��������\n");
	display(mine, ROWS, COLS);//Ϊ������Ϸ��������ʾ����
}

void test()//Ϊʹ��������࣬��ʹ��ӡ�˵�ָ�����ڴ�
{
	int input = 0;
	srand((unsigned int)time(NULL));//unsigned��Ϊ����ֵ��ǿ������ת�������NULL�����ǿ�ָ��
									//����ĳ����ַ���Ὣ����ֵ��Я������Ϣ����ָ�������д�һ��
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case PLAY:
			game();
			break;
		case EXIT:
			break;
		default:
			printf("ѡ�����������ѡ��!\n");
			break;
		}
	} while (input);
}

int main()
{
	test();

	system("pause");
	return 0;
}