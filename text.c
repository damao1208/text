#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
void menu()
{
	printf("*********三子棋*************\n");
	printf("******1.play 0.exit*********\n");
	printf("****************************\n");
}
void game()
{
	char ret = 0;
	//数组存放棋盘的信息
	char board[ROW][COL] = { 0 };//全部空格
	//初始话棋盘
	initboard(board,ROW,COL);
	displayboard(board, ROW, COL); 
	while (1)
	{
		//玩家下棋
		playermove(board, ROW, COL);
		displayboard(board,ROW, COL);
		ret = iswin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
		//电脑下棋
		computemove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board,ROW,COL);
		if (ret!='c')
		{
			break;
		}
	}
	if (ret == '#')
		printf("电脑赢\n");
	else if (ret == '*')
		printf("玩家赢\n");
	else
		printf("平局\n");
}
void text()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择");
		scanf("%d", &input);
		switch (input)
		{
		case 1: printf("开始游戏\n");
			game();
			break;
		case 0: printf("结束游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (input);
}
int main()
{
	text();
	return 0;
}