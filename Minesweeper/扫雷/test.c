#define _CRT_SECURE_NO_WARNINGS 

#include "game.h"

void menu()
{
	printf("******************************\n");
	printf("**********1. play ************\n");
	printf("**********0. exit ************\n");
	printf("******************************\n");
}

void game()
{
	char ret = '1';
	char mine[ROWS][COLS] = {'0'}; //存放布置的雷信息
	char show[ROWS][COLS] = {'*'};   //存放排查出的雷信息
	//初始化数组内容
	//mine 没有布置雷时，都为' 0 '
	InitBoard(mine, ROWS, COLS);
	//show 没有排查雷时，都为' * '
	InitBoard(show, ROWS, COLS);

	//设置雷（埋雷）
	SetMine(mine, ROW, COL);

	//打印
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//排查雷
	while (ret)
	{
		ret = Findmine(mine, show, ROW, COL);
		if (ret == '6')
		{
			printf("\n恭喜你排雷成功！！！\n");
			DisplayBoard(mine, ROW, COL);
			printf("游戏结束\n");
			break;
		}
		if(ret)
			DisplayBoard(show, ROW, COL);
		else
			DisplayBoard(mine, ROW, COL);
	}
	

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//生成随机数种子
	do
	{
		menu();
		printf("请选择：>>> ");
		scanf("%d", &input);
		printf("\n");
		switch(input)
		{
			case 1:
				printf("扫雷\n");
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
		}
	} while (input);

	return 0;
}