#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()

{
	printf("==================================\n");
	printf("==========  ɨ��С��Ϸ  ==========\n");
	printf("=====1.��ʼ===2.����===3.�̳�=====\n");
	printf("==================================\n");
}

void teach()
{
	system("cls");

	char teach[ROWS][COLS] = { 0 };

	printf("��ӭ�����̳�\n");

	Sleep(2000);
	system("cls");

	InitBoard(teach,ROWS, COLS, '*');

	DisPlayBoard(teach, ROW, COL);

	printf("����������\n");
	Sleep(4000);
	system("cls");
	printf("��������Ҫɨ����Ŀ��:\n");
	printf("\n��������� 5 8 ������5�У���8��");
	Sleep(4000);
	system("cls");
	printf("Ҳ��������\n");
	Sleep(1500);
	teach[5][8] = '0';

	DisPlayBoard(teach, ROW, COL);

	Sleep(5000);
	system("cls");
	printf("�����ȫ�����ǻṫ����Χ�������");
	Sleep(5000);
	system("cls");
	printf("����ȵ��˵��ף����ǻṫ�����̵�����λ��");
	Sleep(5000);
	system("cls");
	printf("����������������Ϸ����������");
	Sleep(4000);
	system("cls");
	printf("�̳̽���");
	Sleep(4000);
	system("cls");

}

void game()
{
	int input;
	char Mine[ROWS][COLS] = { 0 };
	char Show[ROWS][COLS] = { 0 };

	InitBoard(Mine, ROWS, COLS, '0');//��ʼ������
	InitBoard(Show, ROWS, COLS, '*');//��ʼ����Ϸ��

	BuriedMine(Mine,ROW,COL); //����
    //DisPlayBoard(Mine, ROW, COL);//��ӡ����
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
		printf("\n��ѡ��");
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
				   printf("ѡ�����");
				   break;
		}
		}
    } 
	while (input);

	printf("\n��Ϸ����");
}

int main()
{
	test();
	return 0;
}
