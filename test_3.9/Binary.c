#define _CRT_SECURE_NO_WARNINGS 

#include "Binary.h"

//创建节点
BTNode* BuyNode(BTData val)
{
	BTNode* new = (BTNode*)malloc(sizeof(BTNode));
	if (new == NULL)
	{
		perror("malloc error");
		return;
	}

	new->data = val;
	new->left = new->right = NULL;

	return new;
}

//前序遍历
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

//后序遍历
void BefOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	BefOrder(root->left);
	BefOrder(root->right);
	printf("%d ", root->data);
}

//节点个数
int TreeSize(BTNode* root);

//叶子节点个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if(root->right && root->left)
	{
		return TreeLeafSize(root->left) + TreeLeafSize(root->right);
	}
	else
	{
		return 1;
	}

	//return (root->right && root->left) == NULL ? 1 : TreeLeafSize(root->left) + TreeLeafSize(root->right);


}

//树高度
int TreeHeight(BTNode* root);








