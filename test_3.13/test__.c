#define _CRT_SECURE_NO_WARNINGS 

#include "Binary.h"

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node3->right = node7;

	return node1;

	//注意：上述代码并不是创建二叉树的方式，真正创建二叉树方式后序详解重点讲解。
}

int main()
{
	BTNode* root = CreatBinaryTree();

	//前序遍历
	printf("前序:");
	PrevOrder(root);
	printf("\n");

	//中序遍历
	printf("中序:");
	InOrder(root);
	printf("\n");

	//后序遍历
	printf("后序:");
	BefOrder(root);
	printf("\n");
	printf("\n");

	printf("节点数:%d\n", TreeSize(root));
	printf("节点数:%d\n\n", TreeSize(root));
	
	printf("叶子数:%d\n", TreeLeafSize(root));
	printf("叶子数:%d\n\n", TreeLeafSize(root));

	printf("高度:%d\n", TreeHeight(root));
	printf("高度:%d\n\n", TreeHeight(root));

	/*int k = 0;
	printf("请输入要求第几层的节点数：");
	scanf("%d", &k);*/
	printf("第%d层节点数:%d\n", 5, TreeLevelKSize(root, 5));
	printf("第%d层节点数:%d\n", 4, TreeLevelKSize(root, 4));
	printf("第%d层节点数:%d\n\n", 3, TreeLevelKSize(root, 3));

	int k = 0;
	printf("请输入查找的节点\n");
	scanf("%d", &k);

	if (TreeFind(root, k))
	{
		printf("找到了\n");
	}
	else
	{
		printf("未找到\n");
	}

	return 0;
}






