#include<stdlib.h>
#include<stdio.h>
int maxSub(int a[]);//����������к�
int main(void){
	int a[5][3] = {
		{ -50,17,-42 },
		{ -47,-19,-3 },
		{ 36,-34,-43 },
		{ -30,-43,34 },
		{ -23,-8,-45 }
	};
	int i, j;
	int max, n;
	int maxRoute = 0;
	int route[10];//����������ν�ÿһ�е�����ֵ
	for (i = 0; i<5; i++){
		max = a[i][0];//maxΪ��i�е�����ֵ
		n = 0;//����ֵ�к�
		for (j = 0; j<3; j++)//����ÿһ��Ԫ��
		{
			if (a[i][j]>max){
				max = a[i][j];
				n = j;
			}
		}
		route[i] = max;
		printf("a[%d][%d]=%d\n", i, n, max);
	}
	printf("���·�߳���Ϊ��%d\n", maxSub(route));
	system("pause");
	return 0;
}
int maxSub(int a[]){
	int maxSum = 0, headSum = 0;
	int i;
	for (i = 0; i<5; i++){
		headSum += a[i];
		if (headSum>maxSum)
			maxSum = headSum;
		else if (headSum<0)
			headSum = 0;
	}
	return maxSum;
}