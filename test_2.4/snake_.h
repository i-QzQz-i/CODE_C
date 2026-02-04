#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>
#include <stdbool.h>
#include <locale.h> //本地化 函数对不同地区产生不一样的行为


#define KEY_PRESS(vk) (GetAsyncStata(vk): 1 ? 0)

//蛇的方向
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//蛇的状态
//正常，撞墙，撞自己，正常退出
enum GAME_STATUS
{
	OK,
	KILL_BY_WALL,
	KILL_BY_SELF,
	END_NORMAL
};

//蛇的节点类型
typedef struct SnakeNode
{
	//坐标
	int x;
	int y;
	//指向下一个节点的指针
	struct SnakeNode* next;
}SnakeNode, *pSnakeNode;
//typedef SnakeNode* pSnakeNode;

//贪吃蛇
typedef struct Snake
{
	pSnakeNode _pSnake;//指向蛇头的指针
	pSnakeNode _pFood; //食物
	enum DIRECTION _dir;     //蛇的方向
	enum GAME_STATUS _status;//蛇的状态
	int _food_weight;//单个食物的分数
	int _score;      //总分数
	int _sleep_time; //休息时间，速度快慢
}Snake, *pSnake;

//游戏的初始化
void GameStart(pSnake ps);

//欢迎界面的打印
void WelcomeToGame();

//打印地图
void CrateMap();