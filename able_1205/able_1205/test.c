#include <stdio.h>
#include <stdlib.h>
#include<math.h>
void main()
{
	int a, b, c, i, n;
	double sum;
	for (i = 0; i <=999; ++i)
	{
		if (i>=100)
		{
			n = 3;
		}                    //���i>100��ˮ�ɻ�������ÿ���������η�
		else if(a<10)
		{ 
			n = 1;
		}                   //���i<10��ˮ�ɻ�������ÿ������һ�η�
		else n = 2;         //���i��10��100֮�䣬ˮ�ɻ�������ÿ������ƽ��

		a = i / 100;           //a������ǰ�λ�ϵ�����
		b = (i % 100) / 10;   //b�������ʮλ�ϵ�����
		c = i % 10;           //c������Ǹ�λ�ϵ�����
		sum = pow(a, n) + pow(b, n) + pow(c, n);//pow(a,n)�������a��n�η�
		if(i==sum)
		printf("%d\n", i);
	}
	system("pause");
}