#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

long int mutiply(long int sum)
{
	long int I = 0;
	int judge = 0;
	printf("���˷�ģʽ��������һ�����֣�");
	judge = scanf_s("%ld", &I);
	while (1 == judge)
	{
		sum = sum * I;
		printf("������ɣ���������һ���������Ҫ�˳����밴Q�����û��س�����\n");
		judge = scanf_s("%ld", &I);
	}
	return sum;
}


