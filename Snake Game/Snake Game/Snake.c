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
	wprintf(L"按’1‘加速，’2‘减速\n");
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
		wprintf(L"%lc", WALL);
	}
	//下
	SetPos(0, 26);
	for (count = 0; count < 29; count++)
	{
		wprintf(L"%lc", WALL);
	}
	//左
	for (count = 1; count < 26; count++)
	{
		SetPos(0, count);
		wprintf(L"%lc", WALL);
	}
	//右
	for (count = 1; count < 26; count++)
	{
		SetPos(56, count);
		wprintf(L"%lc", WALL);
	}
}

//创建新节点（蛇身）
//pSnakeNode

void InitSnake(pSnake ps)
{
	int i = 0;
	pSnakeNode cur = NULL;
	for (i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake()::malloc()");
			exit(-1);
		}
		cur->next = NULL;
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;

		//头插法插入链表
		if (ps->_pSnake == NULL) //空链表
		{
			ps->_pSnake = cur;
		}
		else //非空
		{
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
	}
	
	//cur = ps->_pSnake;
	//while (cur)
	//{
	//	SetPos(cur->x, cur->y);
	//	wprintf(L"%lc", BODY);
	//	cur = cur->next;
	//}

	//设置贪吃蛇的属性
	ps->_dir = RIGHT;//默认向右
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;//单位：毫秒
	ps->_status = OK;
}

void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;

again:
	x = (rand() % 27 + 1) * 2;
	y = rand() % 25 + 1;

	//x和y的坐标不能和蛇身体坐标冲突
	pSnakeNode prev = ps->_pSnake;
	while (prev)
	{
		if (x == prev->x && y == prev->y)
		{
			goto again;
		}
		prev = prev->next;
	}

	//创建食物节点
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood()::malloc()");
		exit(-1);
	}

	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;

	SetPos(x, y);
	wprintf(L"%lc", FOOD);

	ps->_pFood = pFood;
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

	//3.创建蛇
	InitSnake(ps);

	//4.创建食物
	CreateFood(ps);
	SetPos(58, 26);
}


void PrintHelpInfo()
{
	SetPos(64, 17);
	wprintf(L"%ls", L"不能穿墙，不能咬到自己");
	SetPos(64, 18);
	wprintf(L"%ls", L"用↑.←.→.↓控制蛇的移动");
	SetPos(64, 19);
	wprintf(L"%ls", L"按’1‘加速，’2‘减速");
	SetPos(64, 20);
	wprintf(L"%ls", L"按ESC退出游戏，按空格暂停游戏");

	SetPos(70, 26);
	wprintf(L"%ls", L"i-QzQz-i制作");
}

#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1)? 1 : 0)

void Pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}

//int NextIsFood(pSnake ps, int x, int y)
//{
//	pSnakeNode pFood = ps->_pFood;
//	if (pFood->x == x && pFood->y == y)
//		return 1;
//	else
//		return 0;
//}

int NextIsFood(pSnake ps, int x, int y)
{
	return (ps->_pFood->x == x && ps->_pFood->y == y);
}

void EatFood(pSnakeNode pn, pSnake ps)
{
	//头插法
	ps->_pFood->next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;

	//释放下一个位置的节点
	free(pn);
	pn = NULL;

	//打印蛇
	pSnakeNode pCode = ps->_pSnake;
	while (pCode)
	{
		SetPos(pCode->x, pCode->y);
		wprintf(L"%lc", BODY);
		pCode = pCode->next;
	}

	//加分
	ps->_score += ps->_food_weight;

	//重新生成食物
	CreateFood(ps);
}

void NoFood(pSnakeNode pn, pSnake ps)
{
	//头插法
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;

	//释放并打印尾节点和蛇
	pSnakeNode pCode = ps->_pSnake;
	while (pCode->next->next)
	{
		SetPos(pCode->x, pCode->y);
		wprintf(L"%lc", BODY);
		pCode = pCode->next;
	}

	//把最后一个节点打印为空格
	SetPos(pCode->next->x, pCode->next->y);
	printf("%c", '  ');
	
	free(pCode->next);
	pCode->next = NULL;

}

void KillByWall(pSnake ps)
{
	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 56 ||
		ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
	{
		ps->_status = KILL_BY_WALL;
	}
}

void KillByMyself(pSnake ps)
{
	pSnakeNode pCode = ps->_pSnake->next;
	while (pCode)
	{
		if (ps->_pSnake->x == pCode->x && ps->_pSnake->y == pCode->y)
		{
			ps->_status = KILL_BY_SELF;
			return;
		}
		pCode = pCode->next;
	}
}

void SnakeMove(pSnake ps)
{
	//创建一个节点，表示蛇即将到的下一个节点
	pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNextNode == NULL)
	{
		perror("SnakeMove()::malloc()");
		exit(-1);
	}

	switch (ps->_dir)
	{
	case UP:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y - 1;
		break;
	case DOWN:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y + 1;
		break;
	case LEFT:
		pNextNode->x = ps->_pSnake->x - 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	case RIGHT:
		pNextNode->x = ps->_pSnake->x + 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	}

	//检测下一个坐标处是否是食物
	if (NextIsFood(ps, pNextNode->x, pNextNode->y))
	{
		/*pNextNode->next = ps->_pSnake;
		ps->_pSnake = pNextNode;
		CreateFood(ps);*/
		EatFood(pNextNode, ps);
	}
	else
	{
		/*pNextNode->next = ps->_pSnake;
		ps->_pSnake = pNextNode;
		free(pCode);
		pCode = NULL;*/
		NoFood(pNextNode, ps);
	}

	//判断是否撞墙
	KillByWall(ps);

	//判断是否撞到自己
	KillByMyself(ps);
}

void GameRun(pSnake ps)
{
	//打印帮助信息
	PrintHelpInfo();
	//检测按键
	do
	{
		//打印总分数和食物的分值
		SetPos(64, 10);
		printf("总分数:%d", ps->_score);
		SetPos(64, 11);
		printf("当前食物的分数:%2d", ps->_food_weight);

		if (KEY_PRESS(VK_UP) && ps->_dir != DOWN)
		{
			ps->_dir = UP;
		}
		else if(KEY_PRESS(VK_DOWN) && ps->_dir != UP)
		{
			ps->_dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT)
		{
			ps->_dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT)
		{
			ps->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			//暂停
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			//正常退出游戏
			ps->_status = END_NORMAL;
		}
		else if (KEY_PRESS(0x31)) //1
		{
			//加速
			if (ps->_sleep_time > 50)
			{
				ps->_sleep_time -= 30;
				ps->_food_weight += 2;
			}
		}
		else if (KEY_PRESS(0x32)) //2
		{
			//减速
			if (ps->_food_weight > 2)
			{
				ps->_sleep_time += 30;
				ps->_food_weight -= 2;
			}
		}
		
		//蛇走一步的过程
		SnakeMove(ps);
		//更改速度
		Sleep(ps->_sleep_time);
		

	} while (ps->_status == OK);
}

//结束游戏 - 善后工作
void GameEnd(pSnake ps)
{
	system("cls");
	SetPos(38, 8);
	switch (ps->_status)
	{
	case END_NORMAL:
		wprintf(L"你主动退出游戏\n");
		break;
	case KILL_BY_WALL:
		wprintf(L"你撞墙了!\n");
		break;
	case KILL_BY_SELF:
		wprintf(L"你撞到了自己！！！\n");
		break;
	}
	SetPos(38, 10);
	printf("你本次游戏总得分：%d",ps->_score);
	if (ps->_score < 100)
		printf("，请再接再厉\n");
	else if (ps->_score >= 100 && ps->_score < 300)
		printf("，还不错\n");
	else
		printf("，666\n");
	
	//释放蛇身节点
	pSnakeNode Next = ps->_pSnake;
	while (Next)
	{	
		ps->_pSnake = ps->_pSnake->next;
		free(Next);
		Next = ps->_pSnake;
	}
	ps->_pSnake = NULL;
	Next = NULL;
}