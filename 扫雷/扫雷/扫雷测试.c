#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()

{
	printf("==================================\n");
	printf("==========  扫雷小游戏  ==========\n");
	printf("=====1.开始===2.结束===3.教程=====\n");
	printf("==================================\n");
}

void teach()
{
	system("cls");

	char teach[ROWS][COLS] = { 0 };

	printf("欢迎来到教程\n");

	Sleep(2000);
	system("cls");

	InitBoard(teach,ROWS, COLS, '*');

	DisPlayBoard(teach, ROW, COL);

	printf("这里是雷区\n");
	Sleep(4000);
	system("cls");
	printf("输入你想要扫除的目标:\n");
	printf("\n如果你输入 5 8 则代表第5行，第8列");
	Sleep(4000);
	system("cls");
	printf("也就是这里\n");
	Sleep(1500);
	teach[5][8] = '0';

	DisPlayBoard(teach, ROW, COL);

	Sleep(5000);
	system("cls");
	printf("如果安全，我们会公布周围埋雷情况");
	Sleep(5000);
	system("cls");
	printf("如果踩到了地雷，我们会公布雷盘的埋雷位置");
	Sleep(5000);
	system("cls");
	printf("具体情况，请进入游戏后亲自体验");
	Sleep(4000);
	system("cls");
	printf("教程结束");
	Sleep(4000);
	system("cls");

}

void game()
{
	int input;
	char Mine[ROWS][COLS] = { 0 };
	char Show[ROWS][COLS] = { 0 };

	InitBoard(Mine, ROWS, COLS, '0');//初始化雷盘
	InitBoard(Show, ROWS, COLS, '*');//初始化游戏盘

	BuriedMine(Mine,ROW,COL); //埋雷
    //DisPlayBoard(Mine, ROW, COL);//打印雷盘
	DisPlayBoard(Show, ROW, COL);
	PlayGame(Mine, Show, ROW, COL);
}

void test()
{
	int input;
	srand((unsigned int)time(NULL));
	menu();
	do
	{
		printf("\n请选择：");
		scanf("%d", &input);
		
		switch (input)
		{
        case 1:
		{
				  game();
				  menu();
				  break;
		}
		case 2:
		{
				  input = 0;
				  break;
		}
		case 3:
		{
				  teach();
				 
				  menu();
				  break;
		}
		default:
		{
				   printf("选择错误");
				   break;
		}
		}
    } 
	while (input);

	printf("\n游戏结束");
}

int main()
{
	test();
	return 0;
}
