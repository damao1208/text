#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void initboard(char board[ROWS][COLS], int rows, int cols ,char set)
{
	int i;
	int j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i;
	int j;
	//printf("  ");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
			printf("%d ", i);
		for (j = 1; j <=col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = easy_count;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
char get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}
void excludemine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int count = get_mine_count(mine, x, y);
	if (count != 0)
	{
		show[x][y] = count + '0';
	}
	else
	{
		show[x][y] = ' ';
		if (show[x - 1][y] == '*')
			excludemine(mine, show, x - 1, y);
		if (show[x - 1][y - 1] == '*')
			excludemine(mine, show, x - 1, y - 1);
		if (show[x][y - 1] == '0')
			excludemine(mine, show, x, y - 1);
		if (show[x + 1][y - 1] == '*')
			excludemine(mine, show, x + 1, y - 1);
		if (show[x + 1][y] == '*')
			excludemine(mine, show, x + 1, y);
		if (show[x + 1][y + 1] == '*')
			excludemine(mine, show, x + 1, y + 1);
		if (show[x][y + 1] == '*')
			excludemine(mine, show, x, y + 1);
		if (show[x - 1][y + 1] == '*')
			excludemine(mine, show, x - 1, y + 1);

	}
}
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x;
	int y;
	int win=0;
	while (win<row*col-easy_count)
	{
		printf("请输入排雷的坐标：.");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标合法
			if (mine[x][y] == '1')
			{
				printf("你死了\n");
				displayboard(mine, row, col);
				break;
			}
			else
			{
				//计算xy坐标旁边有几个雷
				excludemine(mine, show, x, y);				
				displayboard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入错误，请重新输入：");
		}
	}
	if (win == row * col - easy_count)
	{
		printf("你赢了\n");
	}
}