//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�����������
#include<stdio.h>
#include<stdlib.h>
int str(char *string)
{
	int n = 0;
	while (*string)
	{
		n++;
		string++;
	}
	return n;
}
void reverse(char *string)
{
	int len = str(string);
	if (*string)
	{
		char temp = *string;
		*string = *(string + len - 1);
		*(string + len - 1) = '\0';
		reverse(string + 1);
		*(string + len - 1) = temp;
	}
	else
	{
		return;
	}
}
int main()
{
	char s[10] = "abcdef";
	reverse(s);
	printf(" %s\n", s);
	system("pause");
	return 0;
}