#ifndef __GAME_H__
#define __GAME_H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3
void initboard(char board[ROW][COL], int row, int col);//��ʼ������
void disboard(char board[ROW][COL], int row, int col);//��ӡ
void player(char board[ROW][COL]);//�����
void computer(char board[ROW][COL]);//������
char check_win(char board[ROW][COL],int row,int col);//�ж��䣬Ӯ��ƽ�֣�������
static int IsFull(char board[ROW][COL], int row, int col);//�ж������Ƿ�����
#endif
