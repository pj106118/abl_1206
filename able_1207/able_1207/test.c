#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int to_find = 5;                   //to_find����ҪѰ�ҵ�����
	int n = sizeof(a)/sizeof a[0];    //n�����ܸ���
	int left = 0;
	int right = n-1;                 //left��right����Ķ���������±�
	while (1)
	{
		if (to_find > a[(left+right)/2]) //���Ѱ�ҵ�ֵ���м��ֵ�󣬾Ͱ��м�ֵ���±긳�����
		{
			left = (left + right) / 2 +1;
		}
		else if (to_find < a[(left + right) / 2]) ////���Ѱ�ҵ�ֵ���м��ֵ�󣬾Ͱ��м�ֵ���±긳���ұ�
		{
			right = (left + right) / 2 - 1;
		}
		else
			break;
	}
	printf("%d\n", (left + right) / 2);
	system("pause");
	return 0;
}