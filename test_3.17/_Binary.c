#define _CRT_SECURE_NO_WARNINGS 

#include "Binary.h"

//创建节点
BTNode* BuyNode(BTData val)
{
	BTNode* new = (BTNode*)malloc(sizeof(BTNode));
	if (new == NULL)
	{
		perror("malloc error");
		return NULL;
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

//节点个数（X序遍历）
//int TreeSize(BTNode* root)
//{
//	static int size = 0;
//	if (root == NULL)
//	{
//		return;
//	}
//	else
//	{
//		size++;
//	}
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//}

//节点个数（分治递归）
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

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

//树高度（性能较差）（有效率问题，重复计算多）
//int TreeHeight(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//
//	return TreeHeight(root->left) > TreeHeight(root->right) ?
//		 TreeHeight(root->left) + 1: TreeHeight(root->right) + 1;
//
//}

//树高度（性能较好）
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		{
			return 0;
		}

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

		return leftHeight > rightHeight ? 
		   leftHeight + 1 : rightHeight + 1;
}

//二叉树第k层结点个数
int TreeLevelKSize(BTNode* root, int k)
{
	if (k == 0)
	{
		return 0;
	}

	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return (TreeLevelKSize(root->left, k - 1) + TreeLevelKSize(root->right, k - 1));
}

//二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTData x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}

	BTNode* left = TreeFind(root->left, x);
	if (left)
		return left;

	//
	//return TreeFind(root->right, x);
	//

	BTNode* right = TreeFind(root->right, x);
	if (right)
		return right;

	return NULL;
}

//二叉树的销毁
void TreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	TreeDestory(root->left);
	TreeDestory(root->right);
	free(root);
}

#include "Queue.h"

//层序遍历（BFS）（广度优先遍历）
void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if(root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);

		if (front->left)
			QueuePush(&q, front->left);

		if (front->right)
			QueuePush(&q, front->right);

		printf("%d ", front->data);
		QueuePop(&q);
	}
	
	QueueDestory(&q);
}

//判断是否为完全二叉树（多补了一个节点）
//bool TreeComplete(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//
//	if (root)
//		QueuePush(&q, root);
//
//	BTNode* new =  BuyNode(NULL);
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//
//		if (front->left)
//			QueuePush(&q, front->left);
//		else
//			QueuePush(&q, new);
//
//		if (front->right)
//			QueuePush(&q, front->right);
//		else
//			QueuePush(&q, new);
//
//		if (front->data == NULL)
//			break;
//		
//		QueuePop(&q);
//	}
//
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		if (front->data != NULL)
//		{
//			QueueDestory(&q);
//			printf("\nNO\n");
//			return false;
//		}
//		QueuePop(&q);
//	}
//
//	QueueDestory(&q);
//
//	printf("\nYES\n");
//	return true;
//}

//判断是否为完全二叉树
bool TreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	BTNode* new = BuyNode(NULL);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front)
		{
			QueueDestory(&q);
			printf("\nNO\n");
			return false;
		}
		QueuePop(&q);
	}

	QueueDestory(&q);

	printf("\nYES\n");
	return true;
}






