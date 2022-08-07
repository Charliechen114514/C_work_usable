#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

long long int power(long long int sum)
{
	int power = 0;
	int jugde = 0;
	printf("(乘方模式）你的底数是%ld,请输入乘方数：",sum);
	jugde=scanf_s("%ld", &power);
	int basic = sum;
	while (jugde == 1)
	{
		for (int i = 1; i < power; i++)
			sum = basic * sum;
		printf("现在的结果是%ld，如果想要退出，请输入Q键并敲击回车.",sum);
		jugde = scanf_s("%ld", &power);
	}
	return sum;
}
