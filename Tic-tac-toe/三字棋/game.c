#define _CRT_SECURE_NO_WARNINGS 

#include "game.h"

//棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//第一版本
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			if(j != col - 1)
//				printf("%c  |",board[i][j]);
//			else
//				printf("%c  ", board[i][j]);
//		}
//		if (i != col - 1)
//			printf("\n___|___|___\n");
//		else
//			printf("\n   |   |   \n");
//	}
//}

//第二版本
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j != col - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c  ", board[i][j]);
		}
		printf("\n");
		
		for (j = 0; j < col; j++)
		{
			if (i == row - 1)
			{
				if (j != col - 1)
					printf("   |");
				else
					printf("    ");
				continue;
			}
			if (j != col - 1)
				printf("___|");
			else
				printf("___ ");
		}
		printf("\n");
	}
}

//下棋
void PlayerMove1(char board[ROW][COL], int row, int col)//玩家1
{
	printf("玩家1下棋：>\n");
	printf("请输入坐标：> ");

	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x <= row && y <= col && x > 0 && y > 0)
		{
			/*if (j == 1)
				j = 3;
			else if (j == 3)
				j = 1;*/
			if (board[y - 1][x - 1] == ' ')
			{
				board[y - 1][x - 1] = '*';
				break;
			}
			else
				printf("坐标被占用，请重新输入\n\n");
		}
		else
		{
			printf("坐标非法，请重新输入\n\n");
		}
	}
}

void PlayerMove2(char board[ROW][COL], int row, int col)//玩家2
{
	printf("玩家2下棋：>\n");
	printf("请输入坐标：> ");

	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x <= row && y <= col && x > 0 && y > 0)
		{
			/*if (j == 1)
				j = 3;
			else if (j == 3)
				j = 1;*/
			if (board[y - 1][x - 1] == ' ')
			{
				board[y - 1][x - 1] = '#';
				break;
			}
			else
				printf("坐标被占用，请重新输入\n\n");
		}
		else
		{
			printf("坐标非法，请重新输入\n\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)//人机
{
	printf("电脑下棋：> \n");

	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % row;//生成0~2的随机数
		y = rand() % col;//0~2

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}	
}

//判断空位
char IsFull(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	int sum = 0;
	for (x = 0; x < row; x++)
	{
		for(y = 0;y < col;y++)
			if (board[x][y] == ' ')
			{
				sum++;
			}
	}
	if (sum == 0)
	{
		return '!';
	}
	else
		return 'C';
}

//判断输赢
char IsWin(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	int i = 0, j = 0;
	int n = 0, m = 0;
	int a = 0, b = 0;
	int c = 0, d = 0;

	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			//判断row
			if (board[x][y] == '*')
				i++;
			else if (board[x][y] == '#')
				j++;
			//判断col
			if (board[y][x] == '*')
				n++;
			else if (board[y][x] == '#')
				m++;
		}
		if (i == row || n == row)
		{
			return '*';
		}
		else if (j == col || m == col)
		{
			return '#';
		}
		else
		{
			i = 0; j = 0;
			n = 0; m = 0;
		}
	}
	for (y = row-1,x = 0;y >= 0;y--,x++)
		{
			//判断斜线（右）
			if (board[x][x] == '*')
				a++;
			else if (board[x][x] == '#')
				b++;
			//判断斜线（左）
			if (board[x][y] == '*')
				c++;
			else if (board[x][y] == '#')
				d++;
		}
	if (a == row || c == row)
	{
		return '*';
	}
	else if (b == col || d == col)
	{
		return '#';
	}
	else
	{
		return IsFull(board, ROW, COL);//判断棋盘空位
	}
}







