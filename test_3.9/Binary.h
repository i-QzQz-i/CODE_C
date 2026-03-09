#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//递归实现二叉树，递归一个指令施行多次
//递归的本质：把当前问题拆解为相同类型的子问题，返回条件：最小规模的子问题
typedef int BTData;
typedef struct BinaryTreeNode
{
	BTData data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//创建节点
BTNode* BuyNode(BTData val);

//前序遍历
void PrevOrder(BTNode* root);

//中序遍历
void InOrder(BTNode* root);

//后序遍历
void BefOrder(BTNode* root);

//节点个数（X序遍历）
int TreeSize(BTNode* root);

//节点个数（分治递归）
//int TreeSize(BTNode* root);

//叶子节点个数
int TreeLeafSize(BTNode* root);

//树高度
int TreeHeight(BTNode* root);





