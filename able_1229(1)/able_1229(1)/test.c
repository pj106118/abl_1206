//���n��쳲�������(���õݹ�ķ�������ѭ����
//��Դ�����������⣬һ�����ӣ��ڵ��������ܹ�����һ�����ӣ�����ÿ�����Ķ���һ�ԣ�һ��һĸ�����������Ӳ����������ʵ�n����һ���ж��ٶ����ӣ���1,1,2,3,5,8,13.......)
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Fib(int n)
{
	if (n == 1 || n == 2)    //  |��λ��||�߼���
	{
		return 1;
	}
	int last1 = 1;    //��i - 1��
	int last2 = 1;    //��i - 2��
	int cur = 0;       //�� i ��
	for (int i = 3; i <= n; ++i)
	{
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}
int main()
{
	int n;
	printf("������һ�����֣�\n");
	scanf("%d", &n);
	printf("%d \n", Fib(n));
	system("pause");
	return 0;
}