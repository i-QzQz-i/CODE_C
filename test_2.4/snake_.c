#define _CRT_SECURE_NO_WARNINGS 

#include "Snake.h"

void SetPos(short x, short y)
{
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	//定位光标位置
	COORD pos = { x, y };
	SetConsoleCursorPosition(houtput, pos);
}

void WelcomeToGame()
{
	SetPos(38, 10);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
	SetPos(42, 20);
	system("pause");
	system("cls");
	SetPos(38, 8);
	wprintf(L"用↑↓←→控制蛇的移动\n");
	SetPos(38, 10);
	wprintf(L"按’Z‘加速，’X‘减速\n");
	SetPos(39, 12);
	wprintf(L"加速可获得更高的分数\n");
	SetPos(42, 20);
	system("pause");
	system("cls");
}

void CrateMap()
{
	int count = 0;
	//上
	for (count = 0; count < 29; count++)
	{
		wprintf(L"%lc", L'□');
	}
	//下
	SetPos(0, 26);
	for (count = 0; count < 29; count++)
	{
		wprintf(L"%lc",L'□');
	}
	//左
	for (count = 1; count < 26; count++)
	{
		SetPos(0, count);
		wprintf(L"□");
	}
	//右
	for (count = 1; count < 26; count++)
	{
		SetPos(56, count);
		wprintf(L"□");
	}
}

//初始化游戏
void GameStart(pSnake ps)
{
	//0.先设置窗口大小，再光标隐藏
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	//获得标准输出设备的句柄
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	//定义一个光标信息的结构体
	CONSOLE_CURSOR_INFO Cursor = { 0 };
	//获取和houtput句柄相关的控制台上的光标信息
	GetConsoleCursorInfo(houtput, &Cursor);
	//修改光标为不可见
	Cursor.bVisible = false;
	//重新设置与houput句柄相关的控制台上的光标信息
	SetConsoleCursorInfo(houtput, &Cursor);

	//1.打印环境界面和功能介绍
	WelcomeToGame();

	//2.绘制地图
	CrateMap();
	//4.创建蛇
	//5.创建食物
	//6.设置游戏相关信息
	system("pause");
}













//int main()
//{
//	system("mode con cols=100 lines=30");
//	system("title 贪吃蛇");
//
//	
//	HANDLE houtput = NULL;
//	houtput = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	
//	CONSOLE_CURSOR_INFO cursor = { 0 };
//
//	，存放在  中
//	Get
//	//修改光标
//
//	
//	Set
//
//
//	
//	COORD pos = { x , y };
//
//
//	//设置本地化
//	
//
//	system("pause");
//	return 0;
//}
