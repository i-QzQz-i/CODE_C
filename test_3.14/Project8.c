#define _CRT_SECURE_NO_WARNINGS 

	//相同的树（判断两棵树是否相同）
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == q && q == NULL)
//    {
//        return true;
//    }
//    else if (p == NULL && q != NULL)
//    {
//        return false;
//    }
//    else if (p != NULL && q == NULL)
//    {
//        return false;
//    }
// 
//	  /*if(p == NULL || q == NULL)
//			return false;*/
// 
//    if (p->val != q->val)
//    {
//        return false;
//    }
//
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}

	//对称二叉树（判断两棵树是否对称）
//bool _isSymmetric(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p == NULL || q == NULL)
//        return false;
//
//    if (p->val != q->val)
//        return false;
//
//    return _isSymmetric(p->left, q->right) && _isSymmetric(q->left, p->right);
//}
//
//bool isSymmetric(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return true;
//    }
//
//    return _isSymmetric(root->right, root->left);
//}

	//二叉树的前序遍历（中后序遍历略）
//int TreeCapacity(struct TreeNode* root)
//{
//    return root == NULL ? 0 : TreeCapacity(root->left) + TreeCapacity(root->right) + 1;
//}
//
//void PrevOrder(struct TreeNode* root, int* a, int* i)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//
//    a[(*i)++] = root->val;
//    PrevOrder(root->left, a, i);
//    PrevOrder(root->right, a, i);
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//    if (root == NULL)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//
//    *returnSize = TreeCapacity(root);
//    int* a = (int*)malloc(sizeof(int) * (*returnSize));
//
//    int i = 0;
//    PrevOrder(root, a, &i);
//
//    return a;
//}

	//另一颗树的子树（一颗树的子树是否与另一颗树相同）
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == q && q == NULL)
//    {
//        return true;
//    }
//    if (p == NULL || q == NULL)
//        return false;
//
//    if (p->val != q->val)
//    {
//        return false;
//    }
//
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (root == NULL)
//    {
//        return false;
//    }
//
//    if (root->val == subRoot->val && isSameTree(root, subRoot))
//        return true;
//
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}