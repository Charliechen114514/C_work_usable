#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

long long int power(long long int sum)
{
	int power = 0;
	int jugde = 0;
	printf("(�˷�ģʽ����ĵ�����%ld,������˷�����",sum);
	jugde=scanf_s("%ld", &power);
	int basic = sum;
	while (jugde == 1)
	{
		for (int i = 1; i < power; i++)
			sum = basic * sum;
		printf("���ڵĽ����%ld�������Ҫ�˳���������Q�����û��س�.",sum);
		jugde = scanf_s("%ld", &power);
	}
	return sum;
}
