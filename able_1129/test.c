#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define HASH_LEN 45
#define M 43
#define NAME_NO 30

//ȷ���洢�ṹ�����������ó����������͵����Ͷ���
typedef struct
{
	char name[20];
	int k;            //���ֵ�ASCLL��ֵ
	int s;            //��־                          
}HASH;               //��ϣ��Ķ���
HASH HashList[HASH_LEN];
void InitiltHash(HASH HashList[])
{
	int i;
	for (i = 0; i < HASH_LEN; i++)
	{
		strcpy(HashList[i].name, "");
		HashList[i].k = 0;
		HashList[i].s = 0;
	}
}
int hash(int k)
{
	return k%M;
}
int asc(char a[])
{
	int i = 0;
	int b = 0;
	while (a[i] != '\0')
	{
		b += (int)a[i];
		i++;
	}
	return b;
}


//�������ó���������������Ҫ������α���㷨
int Creathash(HASH HashList[])
{
	int j, f, m;
	char a[20];
	printf("����������:");
	scanf("%s", a);
	j = asc(a);
	f = hash(j);
	m = f;
	while (HashList[f].s != 0)
	{
		f = (f + 1) % M;
		if (f == m)
		{
			printf("��ϣ���Ѵ���!\n");
			return 0;
		}
	}
	strcpy(HashList[f].name, a);
	HashList[f].k = j;
	HashList[f].s = 1;
	return 0;
}             // ������ϣ��


int Findname(HASH HashList[], char a[])
{
	int j, f, m;
	int q = 1;

	j = asc(a);
	f = hash(j);
	m = f;
	printf("\n");
	while (HashList[f].k != 0)
	{

		if (strcmp(HashList[f].name, a) == 0)
		{
			printf("����:%s,������AscΪ:%d,���ҵĳ���Ϊ:1\t\n", HashList[f].name, HashList[f].k);
			return 0;
		}
		else
		{
			f = (f + 1) % M;
			if (strcmp(HashList[f].name, a) == 0)
			{
				q++;
				printf("����:%s,������AscΪ:%d,���ҵĳ���Ϊ:%d\t\n", HashList[f].name, HashList[f].k, q);
				return 0;
			}
		}
	}
	printf("û������Ҫ���ҵ�Ԫ��!\n");
	return -1;
}               //��������

void print(HASH HashList[])
{
	int i;
	printf("���  ����     ASCLL��ֵ  �����־ \n");
	for (i = 0; i < HASH_LEN; i++)
	{
		if (HashList[i].s != 0)
		{
			printf("%d %s ", i, HashList[i].name);
			printf("%d ", HashList[i].k);
			printf("%d ", HashList[i].s);
			printf("\n");

		}
	}
}                 //��ӡ��ϣ����


void main()
{
	int j, i = 1;
	printf("*************��ϣ��Ľ��������!*************\n");
	InitiltHash(HashList);
	while (i)
	{
		printf("\n1.��������  2.��������   3.��ӡ������   4.�˳�����\n");
		printf("  �������Ӧ�ĺ��룬ѡ�����Ĳ���!\n");
		scanf("%d", &j);
		switch (j)
		{
		case 1:  Creathash(HashList); break;
		case 2: {	printf("\n\n����������Ҫ���ҵ�������ƴ��:");
			char a[20] = { 0 };
			scanf("%s", a);
			Findname(HashList, a);
			break;
		}
		case 3:  print(HashList); break;
		case 4:  i = 0; break;
		default:
			printf("  ������������������ѡ��\n");
			break;
		}
	}
}

