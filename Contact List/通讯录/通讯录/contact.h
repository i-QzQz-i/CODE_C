#pragma once

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>

#define PEO_SZ 3
#define INC_SC 2
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

//菜单选项
enum
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	
};

//定义个人信息
typedef struct PeoInfor
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfor;


//定义通讯录
// 
//静态版本//
//typedef struct Contact
//{
//	PeoInfor date[MAX];//存放100人的信息
//	int count;//记录实际的人个数
//}Contact;
//
//动态版本//
typedef struct Contact
{
	PeoInfor* data;//存放人的信息
	int count;//记录实际的人个数
	int capacity;//当前通讯录的容量
}Contact;


//初始化通讯录
int InitContact(Contact* pc);

//通讯录扩容
void CheckCapacity(Contact* pc);

//保存通讯录到文件
void SaveContact(Contact* pc);

//加载文件信息到通讯录
void LoadContact(Contact* pc);

//0.销毁通讯录
void DestroyContact(Contact* pc);

//1.增加联系人
void AddContact(Contact* pc);

//2.删除指定联系人
void DelContact(Contact* pc);

//3.查找指定联系人
void SearchContact(const Contact* pc);

//4.修改指定联系人
void ModContact(Contact* pc);

//5.打印通讯录信息
void ShowContact(const Contact* pc);

//6.联系人排序
//按照名字排序
//按照年龄排序
//
void SortContact(Contact* pc);
