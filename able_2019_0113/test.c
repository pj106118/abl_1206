//���ַ������ַ��ĸ���������һ���ַ�����������ַ������ж��ٸ��ַ�

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int length(char*p)

{

	int n = 0;

	while (*p != '\0')
	{
		n++;               //���ȼ�1
		p++;               //ָ�����һλ
	}
	return n;
}

int main(void)
{
	int len;

	char a[100];

	memset(a, 0x00, 100);

	printf("������һ���ַ���:\n");
	gets(a);
	len = length(a);
	printf("�ַ�������Ϊ��%d\n", len);
	system("pause");
	return 0;

}