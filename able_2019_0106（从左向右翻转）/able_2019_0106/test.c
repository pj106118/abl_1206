  //��д������ 
  //unsigned int reverse_bit(unsigned int value);
  //��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned int unit;
unit reverse_bit(int value)
{
	int num = 0;
	for (int i = 0; i < 32; i++)

	{
		
		num += ((value >> i) & 1) * pow(2, 31 - i);  //��ת����ֵ��pow��2��31-i����

	}

	return num;
}

int main()
{
	int num , value;
	printf("������һ��������\n");
	scanf("%d", &value);
	num = reverse_bit(value);
	printf("%u\n", num);               //��ʮ������ʽ���
	system("pause");
	return 0;
}