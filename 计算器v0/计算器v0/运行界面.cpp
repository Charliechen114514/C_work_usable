#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include"compute.h"

int main()
{   
	printf("**********************���ü�����*************************\n");
	printf("��������ĵ�һ������(��q����):");
	long int sum;
	int judge = scanf_s("%ld",&sum);
	
	while (judge == 1)
	{
		printf("������.");
	    Sleep(1000);
	 	printf("**********************���ü�����*************************\n");//�˵�����
		printf("��ʼ���ɹ���������ĵ�һ��������%ld\n", sum);
		printf("**********************���ü�����*************************\n");
		printf("���ڵĽ����:%ld\n", sum);
		printf("**********************���ü�����*************************\n");
		printf("1:�ӷ�                                           2������\n");
		printf("3:�˷�                                           4������\n");
		printf("5:�˷�                                           6����  \n");
		printf("**********************���ü�����*************************\n");
	yep:printf("������������Ĺ��ܴ���:");
		int a;
		scanf_s("%d", &a);//���ܺ��������
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
		default:printf("��Ǹ�������ǲ�����ʲô���⣿\n");
		}
		printf("���ڵĽ����%ld\n", sum);
		printf("�Ƿ�����������������ּ���������Q�˳�\n");
		getchar();
		judge= scanf_s("%ld", &judge);
	}
		;
printf("лл���ʹ��!");
	return 0;
}