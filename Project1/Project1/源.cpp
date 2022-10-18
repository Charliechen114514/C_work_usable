//命令行界面绘图示例
//@author: LBW 

#include <windows.h>
#include <stdio.h>
#include <math.h>

//画面宽高 
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 80
//圆周率 
#ifndef PI
#define PI 3.141593f 
#endif

//移动光标到指定坐标
//左上角为原点，向右为x正方向，向下为y正方向 
void moveCursor(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//绘制"##"形成的一个点 
//画面中心为原点，向右为x正方向，向上为y正方向 
void drawPoint(float x, float y)
{
	if (x <= -SCREEN_WIDTH / 2 || x >= SCREEN_WIDTH / 2 || y <= -SCREEN_HEIGHT / 2 || y >= SCREEN_HEIGHT / 2)
		return;
	moveCursor((SCREEN_WIDTH / 2 + x) * 2, SCREEN_HEIGHT / 2 - y);
	printf("##");
}

//清除一个点
//坐标与drawPoint一致
void clearPoint(float x, float y)
{
	if (x <= -SCREEN_WIDTH / 2 || x >= SCREEN_WIDTH / 2 || y <= -SCREEN_HEIGHT / 2 || y >= SCREEN_HEIGHT / 2)
		return;
	moveCursor((SCREEN_WIDTH / 2 + x) * 2, SCREEN_HEIGHT / 2 - y);
	printf("  ");
}

//绘制画面边界
//注：会将画面原有图像也覆盖 
void drawEdge()
{
	moveCursor(0, 0);
	for (int y = 0; y <= SCREEN_HEIGHT; y++)
	{
		char line[(SCREEN_WIDTH + 1) * 2 + 2] = { 0 };
		for (int x = 0; x <= SCREEN_WIDTH * 2 + 1; x++)
		{
			if (y == 0 || y == SCREEN_HEIGHT)
				line[x] = '-';
			else if (x == 0 || x == SCREEN_WIDTH * 2 + 1)
				line[x] = '|';
			else
				line[x] = ' ';
		}
		puts(line);
	}
}

//隐藏光标 
void hideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//清除全屏字符
void clearScreen()
{
	system("cls");
}

#define SLOW 0.01


double slow(double n)
{
	n = SLOW * n;
	return n;
}
typedef struct object {
	double pos_x;
	double pos_y;
	double v_x;
	double v_y;
	double a_x;
	double a_y;
	double m;
}object;
void SCANNER(object* pobj)
{
	int ch = 1;
	int ch2[7] = { 0 };
	A:while (ch != 0)
	{
		printf("请输入横向加速度");
		ch=scanf_s("%f", &pobj->a_x);
		ch2[0] = ch;
		printf("请输入纵向加速度");
		ch=scanf_s("%f", &pobj->a_y);
		ch2[1] = ch;
		printf("请输入横向速度");
		ch=scanf_s("%f", &pobj->v_x);
		ch2[2] = ch;
		printf("请输入纵向速度");
		ch=scanf_s("%f", &pobj->v_y);
		ch2[3] = ch;
		printf("请输入横坐标");
		ch=scanf_s("%f", &pobj->pos_x);
		ch2[4] = ch;
		printf("请输入纵坐标");
		ch=scanf_s("%f", &pobj->pos_y);
		ch2[5] = ch;
		printf("请输入质量:");
		ch= scanf_s("%f", &pobj->m);
		ch2[6] = ch;
		for (int i = 0; i < 7; i++)
		{
			if (ch2[i] == 0)
			{
				ch = 1;
				printf("检查你的错误输入");
				goto A;
			}
		}
		ch = 0;
	}
	
}
void Check(object* pobj)
{
	if (pobj->a_x > 3 && pobj->a_y>3 && pobj->v_x>5 && pobj->v_y>5)
	{
		printf("值太大了，重新输入！\n");
		SCANNER(pobj);
	}
}
int main()
{
	int Force = 1;
	int A = Force;
	double pertime = 1;//定义单位时间
	double v = A * pertime;
	hideCursor();//隐藏光标 
	while (1)
	{
		//初始化我们的物体属性
		object object2={-20,-20,3,5,0,0};
		object object1={20,20,2,10,1,1};
		//初始化单个物体：
		object* p_obj = &object1;
		object* p_obj2 = &object2;
		printf("注意此输入无效：改进：采用数组一对一输入，但是我懒得改了。。。");
		SCANNER(p_obj);
		SCANNER(p_obj2);//注意此输入无效：改进：采用数组一对一输入，但是我懒得改了。。。
		int choice = 0;
		double R_square = (p_obj->pos_x - p_obj2->pos_x) * (p_obj->pos_x - p_obj2->pos_x) + (p_obj->pos_y - p_obj2->pos_y) * (p_obj->pos_y - p_obj2->pos_y);
		double G = (p_obj->m * p_obj2->m) / R_square;
		double dx = p_obj->pos_x - p_obj2->pos_x;
		double dy = p_obj->pos_y - p_obj2->pos_y;
		double X_WAY_A = G * dx / (sqrt(R_square)*p_obj->m);
		double Y_WAY_A = G * dy/ (sqrt(R_square)*p_obj2->m);
		clearScreen();//清空屏幕 
		drawEdge();//绘制边界
		for (;;)
		{
			if (choice == 0)//不考虑引力输入
			{
				drawPoint(p_obj->pos_x + pertime * (p_obj->v_x) + 0.5 * p_obj->a_x * pertime * pertime, p_obj->pos_y + pertime * (p_obj->v_y) + 0.5 * p_obj->a_y * pertime * pertime);
				Sleep(10);
				clearPoint(p_obj->pos_x + pertime * (p_obj->v_x) + 0.5 * p_obj->a_x * pertime * pertime, p_obj->pos_y + pertime * (p_obj->v_y) + 0.5 * p_obj->a_y * pertime * pertime);
				p_obj->pos_x = p_obj->pos_x + pertime * (p_obj->v_x) + 0.5 * p_obj->a_x * pertime * pertime;
				p_obj->pos_y = p_obj->pos_y + pertime * (p_obj->v_y) + 0.5 * p_obj->a_y * pertime * pertime;
				p_obj->v_x = p_obj->v_x + pertime * (p_obj->a_x);
				p_obj->v_y = p_obj->v_y + pertime * (p_obj->a_y);
				Sleep(10);
				if (p_obj->pos_x >= SCREEN_WIDTH / 2 - 1 || p_obj->pos_x <= -SCREEN_WIDTH / 2 + 1)
					p_obj->v_x = -p_obj->v_x;
				if (p_obj->pos_y >= SCREEN_HEIGHT / 2 - 1 || p_obj->pos_y <= -SCREEN_HEIGHT / 2 + 1)
					p_obj->v_y = -p_obj->v_y;
				drawPoint(p_obj2->pos_x + pertime * (p_obj2->v_x) + 0.5 * p_obj2->a_x * pertime * pertime, p_obj2->pos_y + pertime * (p_obj2->v_y) + 0.5 * p_obj2->a_y * pertime * pertime);
				Sleep(10);
				clearPoint(p_obj2->pos_x + pertime * (p_obj2->v_x) + 0.5 * p_obj2->a_x * pertime * pertime, p_obj2->pos_y + pertime * (p_obj2->v_y) + 0.5 * p_obj2->a_y * pertime * pertime);
				p_obj2->pos_x = p_obj2->pos_x + pertime * (p_obj2->v_x) + 0.5 * p_obj2->a_x * pertime * pertime;
				p_obj2->pos_y = p_obj2->pos_y + pertime * (p_obj2->v_y) + 0.5 * p_obj2->a_y * pertime * pertime;
				p_obj2->v_x = p_obj2->v_x + pertime * (p_obj2->a_x);
				p_obj2->v_y = p_obj2->v_y + pertime * (p_obj2->a_y);
				Sleep(10);
				if (p_obj2->pos_x >= SCREEN_WIDTH / 2 - 1 || p_obj2->pos_x <= -SCREEN_WIDTH / 2 + 1)
					p_obj2->v_x = -p_obj2->v_x;
				if (p_obj2->pos_y >= SCREEN_HEIGHT / 2 - 1 || p_obj2->pos_y <= -SCREEN_HEIGHT / 2 + 1)
					p_obj2->v_y = -p_obj2->v_y;
			}
			else {

		
			hideCursor();//隐藏光标 
			float x1 = 20;
			float y1 = 20;
			float vx1 = 5;
			float vy1 = 1;
			float x2 = -20;
			float y2 = -20;
			float vx2 = -1;
			float vy2 = 3;
			float m1 = 0.01;
			float m2 = 0.02;
			float G = 6.67;
			x1 = p_obj->pos_x;
			y1 = p_obj->pos_y;
			x2 = p_obj2->pos_x;
			y2 = p_obj2->pos_x;
			vx1 = p_obj->v_x;
			vy1 = p_obj->v_y;
			vx2=p_obj2->v_x;
			vy2= p_obj2->v_x;
			m1 = p_obj->m;
			m2 = p_obj2->m;
			while (1)
			{
				clearScreen();//清空屏幕 
				drawEdge();//绘制边界 
				while (1)
				{
					if (y1 >= SCREEN_HEIGHT / 2 || y1 <= -SCREEN_HEIGHT / 2)
					{
						vy1 = -vy1;
					}
					else if (x1 >= SCREEN_WIDTH / 2 || x1 <= -SCREEN_WIDTH / 2)
					{
						vx1 = -vx1;
					}
					if (y2 >= SCREEN_HEIGHT / 2 || y2 <= -SCREEN_HEIGHT / 2)
					{
						vy2 = -vy2;
					}
					else if (x2 >= SCREEN_WIDTH / 2 || x2 <= -SCREEN_WIDTH / 2)
					{
						vx2 = -vx2;
					}

					double R = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
					float cx = x1 - x2;
					float cy = y1 - y2;
					float a1 = G * m2 / (R * R);
					float a2 = G * m1 / (R * R);
					float j = sqrt(cx * cx + cy * cy);
					float ax1 = (cx / j) * a1;
					float ay1 = (cy / j) * a1;
					float ax2 = (cx / j) * a2;
					float ay2 = (cy / j) * a2;
					if (cx > 0)
					{
						vx1 = vx1 - ax1;
						vx2 = vx2 + ax2;
					}
					else
					{
						vx1 = vx1 + ax1;
						vx2 = vx2 - ax2;
					}
					if (cy > 0)
					{
						vy1 = vy1 - ay1;
						vy2 = vy2 + ay2;
					}
					else
					{
						vy1 = vx1 + ax1;
						vx2 = vx2 - ax2;
					}
					if (R == 0)
					{
						vx1 = (vx1 * (m1 - m2) + 2 * m2 * vx2) / (m1 + m2);
						vy1 = (vy1 * (m1 - m2) + 2 * m2 * vy2) / (m1 + m2);
						vx2 = (vx2 * (m2 - m1) + 2 * m1 * vx1) / (m1 + m2);
						vy2 = (vy2 * (m2 - m1) + 2 * m1 * vy1) / (m1 + m2);
					}

					x1 = x1 + vx1;
					y1 = y1 + vy1;
					x2 = x2 + vx2;
					y2 = y2 + vy2;
					drawPoint(x1, y1);
					Sleep(100);
					clearPoint(x1, y1);
					drawPoint(x2, y2);
					Sleep(100);
					clearPoint(x2, y2);
				}
			}
			}
			/*else
			{
				if (R_square >= 5)
				{
				
					drawPoint(p_obj->pos_x + pertime * (p_obj->v_x) + 0.5 * p_obj->a_x * pertime * pertime, p_obj->pos_y + pertime * (p_obj->v_y) + 0.5 * p_obj->a_y * pertime * pertime);
					Sleep(100);
					p_obj->a_x = p_obj->a_x - X_WAY_A;
					p_obj->a_y = p_obj->a_y - Y_WAY_A;
					p_obj2->a_x = p_obj2->a_x - X_WAY_A;
					p_obj2->a_y = p_obj2->a_y - Y_WAY_A; 
					clearPoint(p_obj->pos_x + pertime * (p_obj->v_x) + 0.5 * p_obj->a_x * pertime * pertime, p_obj->pos_y + pertime * (p_obj->v_y) + 0.5 * p_obj->a_y * pertime * pertime);
					p_obj->pos_x = p_obj->pos_x + pertime * (p_obj->v_x) + 0.5 * p_obj->a_x * pertime * pertime;
					p_obj->pos_y = p_obj->pos_y + pertime * (p_obj->v_y) + 0.5 * p_obj->a_y * pertime * pertime;
					p_obj->v_x = p_obj->v_x + pertime * (p_obj->a_x);
					p_obj->v_y = p_obj->v_y + pertime * (p_obj->a_y);
					Sleep(100);
					if (p_obj2->pos_x >= SCREEN_WIDTH / 2 - 1 || p_obj2->pos_x <= -SCREEN_WIDTH / 2 + 1)
						p_obj2->v_x = -p_obj2->v_x;
					if (p_obj2->pos_y >= SCREEN_HEIGHT / 2 - 1 || p_obj2->pos_y <= -SCREEN_HEIGHT / 2 + 1)
						p_obj2->v_y = -p_obj2->v_y;
					drawPoint(p_obj2->pos_x + pertime * (p_obj2->v_x) + 0.5 * p_obj2->a_x * pertime * pertime, p_obj2->pos_y + pertime * (p_obj2->v_y) + 0.5 * p_obj2->a_y * pertime * pertime);
					Sleep(100);
					clearPoint(p_obj2->pos_x + pertime * (p_obj2->v_x) + 0.5 * p_obj2->a_x * pertime * pertime, p_obj2->pos_y + pertime * (p_obj2->v_y) + 0.5 * p_obj2->a_y * pertime * pertime);
					p_obj2->pos_x = p_obj2->pos_x + pertime * (p_obj2->v_x) + 0.5 * p_obj2->a_x * pertime * pertime;
					p_obj2->pos_y = p_obj2->pos_y + pertime * (p_obj2->v_y) + 0.5 * p_obj2->a_y * pertime * pertime;
					p_obj2->v_x = p_obj2->v_x + pertime * (p_obj2->a_x);
					p_obj2->v_y = p_obj2->v_y + pertime * (p_obj2->a_y);
					Sleep(100);
					if (p_obj2->pos_x >= SCREEN_WIDTH / 2 - 1 || p_obj2->pos_x <= -SCREEN_WIDTH / 2 + 1)
						p_obj2->v_x = -p_obj2->v_x;
					if (p_obj2->pos_y >= SCREEN_HEIGHT / 2 - 1 || p_obj2->pos_y <= -SCREEN_HEIGHT / 2 + 1)
						p_obj2->v_y = -p_obj2->v_y;
				}
				if (R_square <= 5)
				{
					p_obj->a_x = p_obj->a_y = 0;
					p_obj2->a_x = p_obj2->a_y = 0;
					p_obj->v_x /= 100;
					p_obj->v_y /= 100;
					p_obj2->v_x /= 100;
					p_obj2->v_y /= 100;
					if (R_square == 0)
					{
						p_obj->v_x = -p_obj->v_x;
						p_obj->v_y = -p_obj->v_y;
				/*p_obj2->v_x = -p_obj2->v_x;*/
					/*	p_obj2->v_y = -p_obj2->v_y;
					}*/
				/*}*/
		/*	}*/

		}
	}
}
//
// 		   
//		//绘制螺旋曲线（显示轨迹） 
//		float radius = 0;
//		for (float angle = 0; angle < 6 * PI; angle += PI / 180)
//		{
//			drawPoint(radius * cos(angle), radius * sin(angle));
//			radius += 0.03;
//			Sleep(10);//让程序等待10ms否则运行太快 
//		}
//
//		clearScreen();//清空屏幕 
//		drawEdge();//绘制边界 
//
//		radius = 0;
//		//绘制螺旋曲线（不显示轨迹）
//		for (float angle = 0; angle < 6 * PI; angle += PI / 180)
//		{
//			drawPoint(radius * cos(angle), radius * sin(angle));
//			Sleep(10);//注意等待应在擦除之前，否则字符留存时间太少看不清 
//			clearPoint(radius * cos(angle), radius * sin(angle));//擦除刚画出的点 
//			radius += 0.03;
//		}
//	}
//}
