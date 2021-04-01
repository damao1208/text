#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include"game.h"

void menu()
{
	printf("**************扫雷*****************\n");
	printf("************1.play*****************\n");
	printf("************0.exit*****************\n");
	printf("***********************************\n");
	printf("***********************************\n");

}
void game()
{
	//雷的信息存储
	//1布置好雷的信息
	char mine[ROWS][COLS] = { 0 };//11*11 
	//2排查出雷的信息
	char show[ROWS][COLS] = { 0 };//11*11
	initboard(mine, ROWS, COLS ,'0');
	initboard(show, ROWS, COLS, '*');
	//打印棋盘
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);
	//布置雷
	setmine(mine, ROW, COL);
	displayboard(mine, ROW, COL);
	//扫雷
	findmine(mine,show,ROW,COL);
}

void text()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误，重新选择");
			break;
		}
	} while (input);
}
int main()
{
	text();

	return 0;
}