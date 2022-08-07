#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

long int mutiply(long int sum)
{
	long int I = 0;
	int judge = 0;
	printf("（乘法模式）请输入一个数字：");
	judge = scanf_s("%ld", &I);
	while (1 == judge)
	{
		sum = sum * I;
		printf("输入完成，请输入下一个数如果想要退出，请按Q键并敲击回车键！\n");
		judge = scanf_s("%ld", &I);
	}
	return sum;
}


