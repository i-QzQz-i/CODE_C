#define _CRT_SECURE_NO_WARNINGS 

#include "Snake.h"

void test()
{
	int ch = 0;
	do
	{
		//创建贪吃蛇
	Snake snake = { 0 };

	//初始化游戏
	//0.设置窗口大小，并隐藏光标
	//1.打印环境界面
	//2.功能介绍
	//3.绘制地图
	//4.创建蛇
	//5.创建食物
	//6.设置游戏相关信息
	GameStart(&snake);

	//运行游戏
	GameRun(&snake);

	//结束游戏 - 善后工作
	GameEnd(&snake);

	//是否再来一局
	SetPos(38, 12);
	printf("再来一局吗？(Y/N) ");
	ch = getchar();
	while(getchar() != '\n'); //去除\n
	system("cls");
	} while (ch == 'Y' || ch == 'y');
	
}

int main()
{
	//设置适配本地化
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));

	test();

	return 0;
}