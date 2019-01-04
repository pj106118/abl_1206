#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define M 9
#define N 9
//0����ͨ·��2����ǽ��,1������λ�ã�3������λ��
int maze[M][N] = {
	{ 2,2,2,2,2,2,2,2,2 },
	{ 2,0,0,0,2,0,0,0,2 },
	{ 2,0,2,0,0,0,2,2,2 },
	{ 2,0,0,2,2,0,0,0,2 },
	{ 2,0,0,0,1,2,2,0,2 },
	{ 2,0,2,0,2,0,0,0,2 },
	{ 2,0,2,0,2,0,0,2,2 },
	{ 2,0,0,0,0,0,0,3,2 },
	{ 2,2,2,2,2,2,2,2,2 }
};


struct best                  //���ڼ�¼���·���Ľṹ��
{
	int min;
	int b[M][N];
}Best;

int m = 4, n = 4;            //����ĳ�ʼλ��
int p = 4, q = 4;           //����λ�ö��ζ�λ
int x = 7, y = 7;            //���ֳ�ʼλ��
int g, answer;		    //g:ͳ����Ч·������ֹ·�����࣬���ѭ�����ȣ�
						//answer:ͳ�Ƹõ�ͼ�����п����ԣ�

void game()  //���Թ���Ϸ������ʱ��ͳ�ƣ��Լ���������ƶ����ƣ���Ϸģ��
{
	int i, j, v = 0, t = 0;          //tΪ��ʼʱ��
									 //v�����ƶ��ɹ���v��1�������0
	char str;                      //����ַ�w,s,a,d
	time_t start, end;
	start = time(NULL);

	maze[x][y] = 3;        //�����ֵ�λ��

	m = p;
	n = q;
	maze[m][n] = 1;    //���¶�λ����λ��

	printf("��ʾ�Թ���\n");     //��ͼ��ʼ��
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (maze[i][j] == 2) {
				printf("��");
			}

			else if (maze[i][j] == 1)
			{
				printf("��");
			}
			else if (maze[i][j] == 3)
			{
				printf("��");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("����w��s��a�� d���ƶ���\n����60����ͨ��\n"); //��ʼ����ͼ

	while (1)
	{
		printf("ʱ�䣺%d\r", t);
		if (kbhit())	 //�������
						 //���������ͷ��ط���ֵ,���򷵻�0.
		{
			str = getch();    //�����û��Ӽ���������ַ���������str��
			if (str == 'w') //��
			{
				if (maze[m - 1][n] == 0)
				{
					maze[m - 1][n] = 1;
					maze[m][n] = 0;
					m = m - 1;
				}
				else if (maze[m - 1][n] == 3)
				{
					maze[m][n] = 0;
					v = 1;
				}
			}
			else if (str == 's')   //��
			{
				if (maze[m + 1][n] == 0)
				{
					maze[m + 1][n] = 1;
					maze[m][n] = 0;
					m = m + 1;
				}
				else if (maze[m + 1][n] == 3)
				{
					maze[m][n] = 0;
					v = 1;
				}
			}
			else if (str == 'a')   //��
			{
				if (maze[m][n - 1] == 0)
				{
					maze[m][n - 1] = 1;
					maze[m][n] = 0;
					n = n - 1;
				}
				else if (maze[m][n - 1] == 3)
				{
					maze[m][n] = 0;
					v = 1;
				}
			}
			else if (str == 'd')  //��
			{
				if (maze[m][n + 1] == 0)
				{
					maze[m][n + 1] = 1;
					maze[m][n] = 0;
					n = n + 1;
				}
				else if (maze[m][n + 1] == 3)
				{
					maze[m][n] = 0;
					v = 1;
				}
			}
			else;

			system("cls");   //cls��Ϊ������
			printf("��ʾ�Թ���\n");  //��ʾ��Ϸ��ͼ
			for (i = 0; i < M; i++)
			{
				for (j = 0; j < N; j++)
				{
					if (maze[i][j] == 2)
					{
						printf("��");
					}

					else if (maze[i][j] == 1)
					{
						printf("��");
					}
					else if (maze[i][j] == 3)
					{
						printf("��");
					}
					else
					{
						printf("  ");
					}
				}
				printf("\n");
			}
			printf("����w��s��a�� d���ƶ���\n����60����ͨ��\n");
		}
		else;

		if (v == 1)  //�ж��Ƿ�ͨ��
		{
			printf("\n��ϲͨ�أ�\n");
			system("pause");
			break;
		}

		if (t>60)   //�涨ʱ�䵽�������Ϸ
		{
			printf("\nδ�ڹ涨ʱ����ͨ�أ���Ϸʧ�ܡ�\n");
			maze[m][n] = 0;   //����������λ��
			system("pause");
			break;
		}

		end = time(NULL);
		t = difftime(end, start);
	}

}

void create_plat()   //�½���ͼ���������ļ���ģ��
{
	int i, j, s;
cc:	printf("������0��2,0����ͨ·��2����ǽ��(�����ÿո����)����������%dx%d���б�Եǽ�������ٴ�����\n", M - 2, M - 2);
	for (i = 1; i <= M - 2; i++)
	{
		printf("��%d��:", i);
		for (j = 1; j <= N - 2; j++)
		{
			scanf("%d", &s);
			if (s == 0 || s == 2)
				maze[i][j] = s;
			else
			{
				system("cls");         //����
				printf("�����������������!\n");
				goto cc;           //��ת��ccȥ��ִ��
			}
		}
	}

aa: printf("����������ĳ�ʼλ��x,y�����У�1~%d,1~%d��:\n", M - 2, N - 2);

	for (i = 0; i<30; i++)
		fflush(stdin);     //������Լ��̵�30��������ַ�����ֹ��ѭ��bug

	scanf("%d,%d", &p, &q);
	if (p <= (M - 2) && q <= (M - 2) && p>0 && q>0)
		maze[p][q] = 1;
	else
	{
		system("cls");    //����
		printf("�����������������,��%dx%d�ķ�Χ�ڡ�\n", M - 2, N - 2);
		goto aa;
	}

bb: printf("���������ֵ�λ��x,y:\n");

	//������Լ��̵�30��������ַ�����ֹ��ѭ��bug
	for (i = 0; i<30; i++)
		fflush(stdin);

	scanf("%d,%d", &x, &y);
	if (x <= (M - 2) && y <= (N - 2) && x>0 && y>0 && (x != p || y != q))
		maze[x][y] = 3;
	else
	{
		system("cls");
		printf("�����������������,��%dx%d�ķ�Χ�ڡ�\n", M - 2, N - 2);
		goto bb;
	}

	//�ļ������ͼ
	FILE *fp;
	fp = fopen("plat.txt", "w");
	for (i = 0; i<M; i++)
	{
		for (j = 0; j<N; j++)
			fprintf(fp, "%d\t", maze[i][j]);
		fprintf(fp, "%c", '\n');
	}
	fprintf(fp, "%d\t", p);
	fprintf(fp, "%d\t", q);
	fprintf(fp, "%d\t", x);
	fprintf(fp, "%d\t", y);
	fclose(fp);

	printf("��ͼ�½����,������ɹ���\n");
	system("pause");
}

void show_plat()   //��ͼչʾģ��
{
	int i, j;
	system("cls");

	maze[x][y] = 3;    //����λ��

	m = p;
	n = q;
	maze[m][n] = 1;      //����λ��

	printf("��ʾ�Թ���\n");  //��ʾ��Ϸ��ͼ
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (maze[i][j] == 2)
			{
				printf("��");
			}

			else if (maze[i][j] == 1)
			{
				printf("��");
			}
			else if (maze[i][j] == 3)
			{
				printf("��");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("����ʾ��ͼ\n");
	system("pause");
}

void alter_plat()    //�޸ĵ�ͼģ��
{
	int i, j, select, a, b;
	FILE *fp;
	while (1)
	{
		system("cls");

		m = p;
		n = q;
		maze[m][n] = 1;

		printf("��ʾ�Թ���\n");  //��ʾ��Ϸ��ͼ
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (maze[i][j] == 2)
				{
					printf("��");
				}

				else if (maze[i][j] == 1)
				{
					printf("��");
				}
				else if (maze[i][j] == 3)
				{
					printf("��");
				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
		printf("  =============----�޸ĵ�ͼ------===================\n");
		printf(" |��ѡ��                                          |\n");
		printf(" |              1.�޸�Ϊǽ�壻                      |\n");
		printf(" |              2.�޸�Ϊͨ·��                      |\n");
		printf(" |              3.�����޸ĵ�ͼ��                    |\n");
		printf(" |              0.�˳��޸Ĺ��ܣ�                    |\n");
		printf("  ===========����������Ӧ����ִ���书�ܣ�===========\n");
		fflush(stdin);  //�������Ļ���
		scanf("%d", &select);

		if (select<4 && select >= 0)
		{
			switch (select)
			{
			case 1:	printf("Χǽ��Ϊ�޸ķ�Χ����Χ��%dx%d\n", M - 2, N - 2);
				printf("����������x,y(��,��)�޸ĵ�ͼ:\n");

				//������Լ��̵�30��������ַ�����ֹ��ѭ��bug
				for (i = 0; i<30; i++)
					fflush(stdin);

				scanf("%d,%d", &a, &b);
				if (a <= (M - 2) && b <= (N - 2) && a>0 && b>0 && maze[a][b] != 1 && maze[a][b] != 3)
					maze[a][b] = 2;
				else
				{
					printf("����������������룬������Χǽ�����ֺ������λ���޸�!\n");
					system("pause");
				}
				break;
			case 2:	printf("Χǽ��Ϊ�޸ķ�Χ����Χ��%dx%d\n", M - 2, N - 2);
				printf("����������x,y(��,��)�޸ĵ�ͼ:\n");
				//������Լ��̵�30��������ַ�����ֹ��ѭ��bug
				for (i = 0; i<30; i++)
					fflush(stdin);

				scanf("%d,%d", &a, &b);
				if (a <= (M - 2) && b <= (N - 2) && a>0 && b>0 && maze[a][b] != 1 && maze[a][b] != 3)
					maze[a][b] = 0;
				else
				{
					printf("����������������룬������Χǽ�����ֺ������λ���޸�!\n");
					system("pause");
				}
				break;
			case 3:
			{			//�ļ���ʽ�����޸ĺ��ͼ
				fp = fopen("plat.txt", "w");
				for (i = 0; i<M; i++)
				{
					for (j = 0; j<N; j++)
						fprintf(fp, "%d\t", maze[i][j]);
					fprintf(fp, "%c", '\n');
				}
				fprintf(fp, "%d\t", p);
				fprintf(fp, "%d\t", q);
				fprintf(fp, "%d\t", x);
				fprintf(fp, "%d\t", y);
				fclose(fp);

				printf("��ͼ�޸����,������ɹ���\n");
				system("pause");
			}
			break;
			case 0: break;
			}
		}
		else
		{
			printf("�밴�涨����!\n");
			system("pause");
		}

		if (select == 0)
			break;
	}
}

void read_plat()  //��ȡ�ļ���ĵ�ͼģ��
{
	int i, j;
	FILE *fp;
	fp = fopen("plat.txt", "r");
	if (!fp)
	{
		printf("�ļ������ڣ������´�!\n");
		system("pause");
	}
	else
	{
		for (i = 0; i<M; i++)
		{
			for (j = 0; j<N; j++)
				fscanf(fp, "%d\t", &maze[i][j]);
			fscanf(fp, "\n");
		}
		fscanf(fp, "%d\t", &p);
		fscanf(fp, "%d\t", &q);    //��ȡ�����λ��
		fscanf(fp, "%d\t", &x);
		fscanf(fp, "%d\t", &y);   //��ȡ���ֵ�λ��
		printf("��ȡ�ɹ�����鿴�µ�ͼ��\n");
		system("pause");
	}
	fclose(fp);
}

void path_result(int p, int q)  
       //ͳ�Ƶ�ͼ�����п��ܳ��ֵ�·����������Ѵ�������ȫ�ֱ���answer
      //����path_result���������ñ�������Ϊ�ݹ���ֹ����ʾ���Ž������
{
	int i, j;
	maze[p][q] = 1;

	if (maze[p][q + 1] == 3 || maze[p][q - 1] == 3 || maze[p + 1][q] == 3 || maze[p - 1][q] == 3)  
		//�жϵ�ǰλ�����������Ƿ�������
	{
		++answer;    //ͳ��һ����ͼ�����п����ԵĴ���
		printf("�Ѽ���%d��,������1 h,������\r", answer);
	}
	// �ݹ鲿�֣���Ѱ��·���Ĳ���
	if (maze[p][q + 1] == 0) path_result(p, q + 1);  //��
	if (maze[p + 1][q] == 0) path_result(p + 1, q);  //��
	if (maze[p][q - 1] == 0) path_result(p, q - 1);  //��
	if (maze[p - 1][q] == 0) path_result(p - 1, q);  //��
	maze[p][q] = 0;

}


void path_best(int p, int q, int l)     //��ʾ����·����ģ��
{
	int i, j, c, k;

	maze[p][q] = 1;

	if (maze[p][q + 1] == 3 || maze[p][q - 1] == 3 || maze[p + 1][q] == 3 || maze[p - 1][q] == 3)   //�жϵ�ǰλ�����������Ƿ�������
	{
		if (Best.min>l)
		{
			Best.min = l;
			for (i = 0; i < M; i++)
				for (j = 0; j< N; j++)
					Best.b[i][j] = maze[i][j];
		}
		g++;
		k = ((double)g / answer) / 2 * 100 + 50;  //�������һ����ɵİٷֱ����

		printf("�����%d%%��������ȴ�\r", k);

		c = g;

		if (c == answer)               //��ֹ����ѭ�����Ƚ�answer��·����
		{
			printf("���о����Ž⣡%d�������е����Ž�\n", answer);
			for (i = 0; i < M; i++)
			{
				for (j = 0; j< N; j++)
					if (Best.b[i][j] == 2)
					{
						printf("��");
					}
					else if (Best.b[i][j] == 1)
						printf("��");
					else if (Best.b[i][j] == 3)
						printf("��");
					else
						printf("  ");
				printf("\n");
			}
			printf("����ʾ���Ž⣬�������ϣ�\n");
			maze[p][q] = 0;
			return;
			exit(0);
		}

	}

	++l;

	if (g != answer)
	{
		if (maze[p][q + 1] == 0) path_best(p, q + 1, l);  //��
		if (maze[p + 1][q] == 0) path_best(p + 1, q, l);  //��
		if (maze[p][q - 1] == 0) path_best(p, q - 1, l);  //��
		if (maze[p - 1][q] == 0) path_best(p - 1, q, l);  //��
	}
	maze[p][q] = 0;
}

void path_find(int p, int q)  //Ѱ��ͨ��·����ģ��
{
	int i, j, c;
	maze[p][q] = 1;

	c = g;
	if (c == 15)               //��ֹ����ѭ������ʱֻ����ʾ15��·�����ɵ��ڡ�
	{
		printf("���о�10�ֿ��з�����������̫������оٲ��꣬��������о�15��\r");
		maze[p][q] = 0;
		return;
		//	exit(0);
	}

	if (maze[p][q + 1] == 3 || maze[p][q - 1] == 3 || maze[p + 1][q] == 3 || maze[p - 1][q] == 3)
		//�жϵ�ǰλ�����������Ƿ�������
	{
		printf("��ʾ·��: \n");
		for (i = 0; i < M; i++)
		{
			for (j = 0; j< N; j++)
			{
				if (maze[i][j] == 2)
				{
					printf("��");
				}
				else if (maze[i][j] == 1)
					printf("��");
				else if (maze[i][j] == 3)
					printf("��");
				else
					printf("  ");
			}
			printf("\n");
		}
		printf("����ʾ���������ϣ�\n");
		g++;
	}

	if (g != 15)
	{
		if (maze[p][q + 1] == 0) path_find(p, q + 1);  //��
		if (maze[p + 1][q] == 0) path_find(p + 1, q);  //��
		if (maze[p][q - 1] == 0) path_find(p, q - 1);  //��
		if (maze[p - 1][q] == 0) path_find(p - 1, q);  //��
	}
	maze[p][q] = 0;
}

void main()   //���������˵����ƽ���
{            //ȫ�ֱ�����m,n����λ�ã�p,q�����ʼλ��x,y���ֵĳ�ʼλ��
			 //gͳ��������Ч·���Ĵ��������ʮ�Σ���ֹ��Ϊ·���������ѭ����
	int select, k;
	time_t start, end;
	int hour, minute, second, t;   //ʱ�����

	while (1)
	{
		system("cls");
		printf("  =============�������Թ���Ϸ n.0===================\n");
		printf(" |��ѡ��                                          |\n");
		printf(" |              1.��ʼ��Ϸ��                        |\n");
		printf(" |              2.�½���ͼ��                        |\n");
		printf(" |              3.�鿴��ͼ��                        |\n");
		printf(" |              4.�޸ĵ�ͼ��                        |\n");
		printf(" |              5.��ȡ��ͼ��                        |\n");
		printf(" |              6.��ʾ���·����                    |\n");
		printf(" |              7.��ʾͨ������·����                |\n");
		printf(" |              0.�˳�ϵͳ��                        |\n");
		printf("  ===========����������Ӧ����ִ���书�ܣ�===========\n");
		printf(" ע������:\n ��ͼ��Ҫȫ��,����Ҫִ��6,7ѡ��,������ʮ�ڴλ��Ѻܳ�ʱ�䣬������ͨ������·��������һ�������ڣ�\n");
		for (k = 0; k<30; k++)
			fflush(stdin);  //������������scanf���棬��ֹ��ѭ��

		scanf("%d", &select);
		if (select >= 0 && select<8)    //����������
		{
			switch (select)
			{
			case 0:  exit(0);
			case 1:	 system("cls");  //����˵� 
				game();        //��ʼ��Ϸ
				break;
			case 2:  create_plat();  //�½���ͼ
				break;
			case 3:  show_plat();   //��ʾ��ͼ
				break;
			case 4:  alter_plat();  //�޸ĵ�ͼ
				break;
			case 5:  read_plat();   //���ļ����ȡ��ͼ
				break;
			case 6:  g = 0; Best.min = 999; answer = 0;
				start = time(NULL);
				path_result(p, q);    //ͳ�Ƶ�ͼ���н�ĸ���
				path_best(p, q, 1);   //Ѱ����̵�·��
				end = time(NULL);
				t = difftime(end, start);
				second = t % 60;     //�����
				minute = t / 60;        //�ܷ���
				hour = minute / 60;      //���Сʱ
				minute = minute % 60;   //�����
				printf("����ʱ�䣺%dh %dm %ds", hour, minute, second);
				//��ʾѰ�����·�������ѵ�ʱ��
				system("pause");
				break;
			case 7:  g = 0;
				path_find(p, q);   //Ѱ������ͨ��·��
				printf("����ʾ����·��! \n");
				system("pause");
				break;
			default:
				break;
			}
		}
		else
		{
			printf("�밴�涨���룡\n");
			system("pause");
		}
	}
}
