#pragma once
#define ROW 3
#define COL 3
#include<stdlib.h>
#include<time.h>
void initboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void computemove(char board[ROW][COL], int row,int col);
char iswin(char board[ROW][COL], int row, int col);