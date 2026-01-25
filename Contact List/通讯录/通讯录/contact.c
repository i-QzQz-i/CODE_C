#define _CRT_SECURE_NO_WARNINGS 

#include "contact.h"

//加载文件信息
void LoadContact(Contact* pc)
{
	FILE* pfRead = fopen("contact.txt", "rb");
	if (pfRead == NULL)
	{
		perror("LoadContact");
		return;
	}

	PeoInfor tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfor), 1, pfRead) == 1)
	{
		CheckCapacity(pc);

		pc->data[pc->count] = tmp;
		pc->count++;
	}

	fclose(pfRead);
	pfRead = NULL;
}

//通讯录初始化
// 
//静态版本使用
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	pc->count = 0;
//	memset(pc->date, 0, sizeof(pc->date));
//}
//动态版本使用
int InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->data = (PeoInfor*)calloc(PEO_SZ,sizeof(PeoInfor));
	if (pc->data == NULL)
	{
		printf("InitContact: %s\n", strerror(errno));
		return 1;
	}
	pc->capacity = PEO_SZ;
	//加载文件信息到通讯录
	LoadContact(pc);
	return 0;
}

//
void CheckCapacity(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		PeoInfor* ptr = realloc(pc->data, (pc->capacity * 2) * sizeof(PeoInfor));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity *= 2;
			printf("增容成功\n");
		}
		else
		{
			printf("AddContact: %s", strerror(errno));
			return;
		}
	}
}
void AddContact(Contact* pc)
{
	assert(pc);
	//静态版本
	//if (pc->count == MAX)
	//{
	//	printf("通讯录已满，无法添加\n");
	//	return;
	//}
	// 动态版本
	CheckCapacity(pc);
	//
	printf("请输入名字：> ");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄：> ");
	scanf("%d", &pc->data[pc->count].age);
	printf("请输入性别：> ");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话：> ");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址：> ");
	scanf("%s", pc->data[pc->count].addr);

	(pc->count)++;
	printf("增加成功\n");
}
//

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	printf("%-20s %-5s %-5s %-12s %-30s\t\n","名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s %-5d %-5s %-12s %-30s\t\n", pc->data[i].name,
												  pc->data[i].age, 
												  pc->data[i].sex, 
												  pc->data[i].tele, 
												  pc->data[i].addr);
	}
}

//查找联系人
static int FindByName1(const Contact* pc, const char* name)
{
	assert(pc);
	assert(name);
	int i = 0, j = 0;

	for (i = 0; i < pc->count; i++)
	{
		j = strcmp(pc->data[i].name, name);
		if (j == 0)
		{
			return i;
		}
	}

	return -1;
}

void DelContact(Contact* pc)
{
	assert(pc);
	int i = 0;
	if (pc->count == 0)
	{
		printf("通讯录为空，无可删除对象\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除联系人的姓名：> ");
	scanf("%s", name);

	//1,查找
	int pos = FindByName1(pc,name);
	//2.删除
	if (pos == -1)
	{
		printf("要删除的联系人不存在\n");
		return;
	}
	else
	{
		for (i = pos;i < pc->count - 1;i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
	}
	pc->count--;
	printf("删除成功\n");
}

void SearchContact(const Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空，无可查找对象\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找联系人的姓名：> ");
	scanf("%s", name);

	int pos = FindByName1(pc, name);
	if (pos == -1)
	{
		printf("要查找的联系人不存在\n");
		return;
	}
	else
	{
		printf("找到了\n");
		printf("%-20s %-5s %-5s %-12s %-30s\t\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s %-5d %-5s %-12s %-30s\t\n", pc->data[pos].name,
												  pc->data[pos].age,
												  pc->data[pos].sex,
												  pc->data[pos].tele,
												  pc->data[pos].addr);
	}
}

void ModContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空，无可修改对象\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改联系人的姓名：> ");
	scanf("%s", name);

	int pos = FindByName1(pc, name);
	if (pos == -1)
	{
		printf("要修改的联系人不存在\n");
		return;
	}
	else
	{
		printf("已找到修改人信息，开始修改\n");
		printf("请输入名字：> ");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄：> ");
		scanf("%d", &pc->data[pos].age);
		printf("请输入性别：> ");
		scanf("%s", pc->data[pos].sex);
		printf("请输入电话：> ");
		scanf("%s", pc->data[pos].tele);
		printf("请输入地址：> ");
		scanf("%s", pc->data[pos].addr);

		printf("修改成功\n");
	}
}

//查找排序
static int com_peo_by_name(const void* e1, const void* e2)
{
	return strcmp((PeoInfor*)e1, (PeoInfor*)e2);
}
//
//按名字排序
void SortContact(Contact* pc)
{
	assert(pc);
	int i = 0, j = 0;
	qsort(pc->data, pc->count, sizeof(pc->data[0]), com_peo_by_name);
	printf("排序成功\n");

}

//释放内存
void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	pc = NULL;
}

//保存文件
void SaveContact(const Contact* pc)
{
	assert(pc);
	FILE* pfWrite = fopen("contact.txt", "wb");
	if (pfWrite == NULL)
	{
		perror("SaveContact");
		return;
	}
	//写文件---二进制
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfor), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
}