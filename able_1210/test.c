#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void init(int arr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		arr[i] = i;
	}
	
}                 //���������Ϊ�˶�������г�ʼ��


void empty(int arr[], int len)
{
	int i = 0;
	for (i = 0; i < len; ++i)
	{
		arr[i] = 0;
		printf("%d\t", arr[i]);
	}
}                     //���������Ϊ�˶���������


void reverse(int arr[], int len)
{
	int i = 0;
	int left = 0;
	int right = len - 1;
	for (i = 0; i < len; ++i)
	{
		arr[i] = i;
	}
	for (i = 0; i < len; ++i)
	{
		while (left < right)
		{
			int num = arr[left];
			arr[left] = arr[right];
			arr[right] = num;
			left++;
			right--;
		}
		printf("%d\n", arr[i]);
	}
}            //���������Ϊ�˶������������


int main()
{
	int a;
	printf("**           1����ʼ������         **\n");
	printf("**           2���������           **\n");
	printf("**           3����������           **\n");
	printf("*************************************\n\n");
	printf("��ѡ��\n");
	scanf("%d", &a);
	int arr[5];
	int len = sizeof(arr) / sizeof(arr[0]);
	switch (a)
	{
	case 1:
		printf("��ʼ�����飺\n");
		init(arr,len); 
		for (int i = 0; i < len; ++i)
			printf("%d\t", arr[i]);
		break;
	case 2:
		printf("������飺\n");
		empty(arr,len);
		break;
	case 3:
		printf("�������飺\n");
		reverse(arr,len); 
		break;
	default:
			break;
	}
	system("pause");
	return 0;
}