#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include"game.h"

void menu()
{
	printf("**************ɨ��*****************\n");
	printf("************1.play*****************\n");
	printf("************0.exit*****************\n");
	printf("***********************************\n");
	printf("***********************************\n");

}
void game()
{
	//�׵���Ϣ�洢
	//1���ú��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//11*11 
	//2�Ų���׵���Ϣ
	char show[ROWS][COLS] = { 0 };//11*11
	initboard(mine, ROWS, COLS ,'0');
	initboard(show, ROWS, COLS, '*');
	//��ӡ����
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);
	//������
	setmine(mine, ROW, COL);
	displayboard(mine, ROW, COL);
	//ɨ��
	findmine(mine,show,ROW,COL);
}

void text()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ���������ѡ��");
			break;
		}
	} while (input);
}
int main()
{
	text();

	return 0;
}