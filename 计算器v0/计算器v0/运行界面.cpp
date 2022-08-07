#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include"compute.h"

int main()
{   
	printf("**********************摆烂计算器*************************\n");
	printf("请输入你的第一个数字(按q走人):");
	long int sum;
	int judge = scanf_s("%ld",&sum);
	
	while (judge == 1)
	{
		printf("加载中.");
	    Sleep(1000);
	 	printf("**********************摆烂计算器*************************\n");//菜单界面
		printf("初始化成功，你输入的第一个数字是%ld\n", sum);
		printf("**********************摆烂计算器*************************\n");
		printf("现在的结果是:%ld\n", sum);
		printf("**********************摆烂计算器*************************\n");
		printf("1:加法                                           2：减法\n");
		printf("3:乘法                                           4：除法\n");
		printf("5:乘方                                           6：爬  \n");
		printf("**********************摆烂计算器*************************\n");
	yep:printf("输入你想输入的功能代码:");
		int a;
		scanf_s("%d", &a);//功能函数代码块
		switch (a)
		{
		case 1:sum=add(sum);
			break;
		case 2:sum=minus(sum);
			break;
		case 3:sum=mutiply(sum);
			break;
		case 4:sum=divide(sum);
			break;
		case 5:sum=power(sum);
			break;
		case 6:
			break;
		default:printf("抱歉，但你是不是有什么问题？\n");
		}
		printf("现在的结果是%ld\n", sum);
		printf("是否继续？输入任意数字继续，输入Q退出\n");
		getchar();
		judge= scanf_s("%ld", &judge);
	}
		;
printf("谢谢你的使用!");
	return 0;
}