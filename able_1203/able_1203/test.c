#include <stdio.h>
#include <stdlib.h>
#define N 10
int init(int arr1[N])
{
	arr1[N] = { 1,2,3,4,5 }
	for (int i = 0; i <= 5; ++i)
	{
		arr1[i] = 0;
	}
	return 0;
}        //���������Ϊ�˶�������г�ʼ��

void empty(int arr1[N])
{
	int i;
	for (i = 0; i < N; ++i)
		arr1[i] = 0;
	printf("�����ɣ�");
}              //���������Ϊ�˶���������

void reverse(int arr1[N])
{
	int arr2[N], i, j;
	for (i = 0, j = N - 1; i < N, j >= 0; ++i, j--)
		arr2[i] = arr1[j];
	for (i = 0; i < N; ++i)
		arr1[i] = arr2[i];
	for (i = 0; i < N; ++i)
		printf("arr[%d]=%2d ", i + 1, arr1[i]);
}            //���������Ϊ�˶������������

int main()
{
	int arr[N], a;
printf("**           1����ʼ������         **\n");
printf("**           2���������           **\n");
printf("**           3����������           **\n");
printf("**           4���˳�               **\n");
printf("*************************************\n\n");
printf("��ѡ��");
scanf("%d", &a);
switch (a)
{
case 1:
	init(arr);
	break;
case 2:
	empty(arr);
	break;
case 3:
	reverse(arr);
	break;
dautle:
	break;
}
system("pause");
return 0;
}
