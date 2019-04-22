#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("*************************\n");
	printf("*****    1.play     *****\n");
	printf("*****    0.exit     *****\n");
	printf("*************************\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	initboard(board, ROW, COL);
	disboard(board, ROW, COL);
	while (1)
	{
		player(board);
		disboard(board, ROW, COL);
		//�ж��������
		ret = check_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		computer(board);
		disboard(board, ROW, COL);
		//�жϵ�������
		ret = check_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if ('*' == ret)
	{
		printf("���Ӯ\n");
	}
	else if ('#' == ret)
	{
		printf("����Ӯ\n");
	}
	else if ('Q' == ret)
	{
		printf("ƽ��\n");
	}
}
int main()
{
	int input = 0;
	do
	{
		menu();
		srand((unsigned int)time(NULL));
		scanf("%d ", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������;\n");
			break;
		}
	} while (input);
	system("pause");
}