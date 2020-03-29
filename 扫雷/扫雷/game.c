#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROWS][COLS], int row, int col, char fill) //初始化
{
	int i, j;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<col; j++)
		{
			board[i][j] = fill;
		}
	}
}


void DisPlayBoard(char board[ROWS][COLS], int row, int col) //打印
{
	int i, j;
	int n = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d   ", i);
	}

	printf("\n   ----------------------------------\n");

	for (i = 1; i<=row; i++)
	{
		printf("%d | ", n + 1);

		for (j = 1; j<=col; j++)
		{
			printf("%c   ", board[i][j]);
		}
		printf("\n\n");
		n++;
	}
}

void BuriedMine(char Mine[ROWS][COLS], int row, int col) //埋雷
{
	
	int i = 0;

	while (i < EASY_GAME)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (Mine[x][y] == '0')
		{
			Mine[x][y] = '1';
			i++;
		}
	}
}

int GetMineCount(char Mine[ROWS][COLS], int x, int y) //计算雷个数
{
	return	( Mine[x + 1][y] +
		 Mine[x][y + 1] +
		 Mine[x + 1][y + 1] +
		 Mine[x - 1][y] +
		 Mine[x][y - 1] +
		 Mine[x - 1][y - 1] +
		 Mine[x + 1][y - 1] +
		 Mine[x - 1][y + 1] - 8 * '0');
}

void FindMine(char Mine[ROWS][COLS], char Show[ROWS][COLS], int x, int y)
{
	if (GetMineCount(Mine, x, y) == 0)
	{
		Show[x][y] = ' ';
		if ((x - 1)>0 && (y - 1)>0 && Show[x - 1][y - 1] == '*')
			FindMine(Mine, Show, x - 1, y - 1);

		if ((y - 1)>0 && Show[x][y - 1] == '*')
			FindMine(Mine, Show, x - 1, y - 1);

		if ((x + 1) <= ROW && (y - 1)>0 && Show[x + 1][y - 1] == '*')
			FindMine(Mine, Show, x + 1, y - 1);

		if ((x + 1) <= ROW && Show[x + 1][y] == '*')
			FindMine(Mine, Show, x + 1, y);

		if ((x + 1) <= ROW && (y + 1) <= COL && Show[x + 1][y + 1] == '*')
		    FindMine(Mine, Show, x + 1, y + 1);

		if ((y + 1) <= COL&&Show[x][y + 1] == '*')
			FindMine(Mine, Show, x, y + 1);

	    if ((x - 1)>0 && (y + 1) <= COL && Show[x - 1][y + 1] == '*')
			FindMine(Mine, Show, x - 1, y + 1);

		if ((x - 1)>0 && Show[x - 1][y] == '*')
			FindMine(Mine, Show, x - 1, y);
	}
	else
		Show[x][y] = GetMineCount(Mine, x, y) + '0';
}

	void PlayGame(char Mine[ROWS][COLS], char Show[ROWS][COLS], int row, int col) //玩游戏部分
{
	int x, y;
	int n = EASY_GAME;
	int i, j;
	int l = -1;

	while (1)
	{
		printf("输入你想要扫除的目标:");
		scanf("%d%d", &x, &y);

		if (Mine[x][y] == '1')
		{
			system("cls");
			Show[x][y] = '!';
			DisPlayBoard(Show, ROW, COL);
			printf("很遗憾，你没了！\n\n");
			DisPlayBoard(Mine, ROW, COL);
			printf("这是雷的布局(数字1代表雷)\n");
			break;
		}
		else if (x > row || y > col || x <= 0 || y <= 0)
		{
			Sleep(1000);
			printf("别胡搞\n");
		}
		else
		{
			system("cls");
			int count = GetMineCount(Mine,x,y);
			Show[x][y] = count + '0';
			FindMine(Mine, Show, x, y);
			DisPlayBoard(Show, ROW, COL); //打印
			for (i = 1; i <= ROW; i++)
			{
				for (j = 1; j <= COL; j++)
				{
					if (Show[i][j] == '*')
					{
						n--;
					}
				}
			}
			if (n == 0)
			{
				l = 0;
				break;
			}		
         }

	}
	if (l == 0)
	{
		printf("恭喜你，排除了全部的地雷\n");
		
	}
	Sleep(4000);
	printf("\n\n\n");
}
