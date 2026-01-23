#define _CRT_SECURE_NO_WARNINGS 

#include "game.h"

//初始化数组
void InitBoard(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (board[0][0] == '0')
				board[i][j] = '0';
			else
				board[i][j] = '*';
		}
	}
}

//打印数组
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------------------扫雷游戏--------------------\n");
	printf("行/列");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	printf("    ");
	for (i = 1; i <= row; i++)
	{
		printf("__");
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d   |", i);
		for (j = 01; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------------------扫雷游戏--------------------\n\n");
}

////////////////////////////////////////////////////////////////////////////////////////

//设置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
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

//标记雷
void IsSign(char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入要标记的坐标：> ");
	while (1) 
	{
		scanf("%d %d", &y, &x);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			show[x][y] = '!';
			DisplayBoard(show, ROW, COL);
			break;
		}
		else
			printf("坐标非法，请重新输入\n");
	}
}

//周围是否有雷
void IsHave(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = 0, j = 0;
	int count = 1;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] != '0')
			{
				count = 0;
				break;
			}
		}
	}
	if (count == 1)
	{
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				show[i][j] = ' ';
			}
		}
	}
}

//判断成功
static char IsWin(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int sum1 = 0;
	int sum2 = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '!')
				sum2++;
			if (mine[i][j] == '1' && show[i][j] == '!')
				sum1++;
		}
	}
	if (sum1 == EASY_COUNT && sum2 == sum1)
		return '6';
	else
		return '1';
}

//排查雷
char Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	int x = 0, y = 0;
	int sum = 0;
	int ret = 1;
	int input = 0;
	int win = 0;

	while (1)
	{
		printf("若需标记请按1,按其他则跳过\n");
		scanf("%d", &input);
		switch (input)
		case 1:
		{
			IsSign(show, ROW, COL);
			break;
		}
		if (input != 1)
			break;
	}

	printf("请输入要排查的坐标：> \n");
	while(1)
	{
		scanf("%d %d", &y, &x);
		if ((x < 1 || x > row) || (y < 1 || y > col))
		{
			printf("输入非法，请重新输入\n");
			continue;
		}
		else if (show[x][y] == ' ')
		{
			printf("重复排查，请重新输入：> ");
			continue;
		}
		if (mine[x][y] == '1')
		{
			printf("\n炸了!!!\n");
			return '\0';
		}
		else
		{
			//基础实现，后用递归实现
			IsHave(mine, show, x, y);//判断周围是否有雷
			win++;
			show[x][y] = ' ';
			for (i = x-1; i <= x+1; i++)
			{
				for (j = y-1; j <= y+1; j++)
				{
					if (mine[i][j] == '1')
					{
						sum++;//统计show[x][y]周围3*3有多少雷
						//转换数字字符
						show[x][y] = sum + '0';//‘1’-‘0’== 1
					}
				}
			}
			if (win == row * col - EASY_COUNT)
			{
				return '6';
			}
			char n = IsWin;
			return n;//判断成功
			//return '1';
		}
	}
}



