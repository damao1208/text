#include "game.h"
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

char isfull(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//棋盘没满
			}
		}
	}
	return 1; //满了
}
void initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void displayboard (char board[ROW][COL], int row, int col)
{
	// A | A | A 
	//---|---|---
	// A | A | A 
	//---|---|---
	// A | A | A 
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if(j<col-1)
			printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|"); 
				}
			}
			printf("\n");
		}
		

	}
}
void playermove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("玩家回合：>");
	while (1)
	{
		printf("请输入要下的坐标");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用");
			}
		}
		else
		{
			printf("坐标非法，请重新输入：");
		}
	}
}
void computemove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("电脑走：>\n");
		x = rand() % row;
		y = rand() % col;
		printf("%d %d\n", x, y);
		if (x >= 0 && x < row && y >= 0 && y < col)
		{
			if (board[x][y] == ' ')
			{
				board[x][y] = '#';
				break;
			}
		}
	}

}
//玩家赢--*
//电脑赢--#
//平局--q
//继续--c
char iswin(char board[ROW][COL], int row, int col)
{
	int i;
	//判断行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][0];
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	//判断对角线
	if (board[0][0] == board[1][1]&& board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1]&& board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//判断平局
	if (1 == isfull(board, ROW, COL))
	{
		return 'q';
	}
	return 'c';

}