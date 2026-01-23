#define _CRT_SECURE_NO_WARNINGS 

#include "game.h"

void menu()
{
	printf("*********************************\n");
	printf("********** 1.人机对战 ***********\n");
	printf("********** 2.玩家对战 ***********\n");
	printf("************ 0.exit *************\n");
	printf("*********************************\n");
}

void game1()//人机对战
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);//打印棋盘
	//开始下棋
	while (1)
	{
		PlayerMove1(board, ROW, COL);//玩家下棋
		printf("\n");
		DisplayBoard(board, ROW, COL);//打印棋盘
		//IsFull(board, ROW, COL);//判断棋盘空位
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//电脑下棋
		printf("\n");
		DisplayBoard(board, ROW, COL);//打印棋盘
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("玩家赢了\n");
		printf("恭喜你！！！\n\n");
	}
	else if(ret == '#')
	{
		printf("电脑赢了\n");
		printf("FW\n\n");
	}
	else
	{
		printf("平局\n\n");
	}
}

void game2()//玩家对战
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);//打印棋盘
	//开始下棋
	while (1)
	{
		PlayerMove1(board, ROW, COL);//玩家1下棋
		printf("\n");
		DisplayBoard(board, ROW, COL);//打印棋盘
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		PlayerMove2(board, ROW, COL);//玩家2下棋
		printf("\n");
		DisplayBoard(board, ROW, COL);//打印棋盘
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("* 玩家1赢了 *\n\n");
	}
	else if (ret == '#')
	{
		printf("# 玩家2赢了 #\n\n");
	}
	else
	{
		printf("平局\n\n");
	}
}


int main()
{
	srand((unsigned int)time(NULL));//设置随机数种子（time）

	int input = 0;
	do
	{
		menu();//打印菜单
		printf("请选择：>>> ");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				printf("三字棋\n");
				game1();
				break;
			case 2:
				printf("三字棋\n");
				game2();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误,请重新输入\n\n");
		}
	} while (input);
	return 0;
}