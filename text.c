#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
void menu()
{
	printf("*********������*************\n");
	printf("******1.play 0.exit*********\n");
	printf("****************************\n");
}
void game()
{
	char ret = 0;
	//���������̵���Ϣ
	char board[ROW][COL] = { 0 };//ȫ���ո�
	//��ʼ������
	initboard(board,ROW,COL);
	displayboard(board, ROW, COL); 
	while (1)
	{
		//�������
		playermove(board, ROW, COL);
		displayboard(board,ROW, COL);
		ret = iswin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
		//��������
		computemove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board,ROW,COL);
		if (ret!='c')
		{
			break;
		}
	}
	if (ret == '#')
		printf("����Ӯ\n");
	else if (ret == '*')
		printf("���Ӯ\n");
	else
		printf("ƽ��\n");
}
void text()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1: printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0: printf("������Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}

	} while (input);
}
int main()
{
	text();
	return 0;
}