#define _CRT_SECURE_NO_WARNINGS 

    //单值二叉树（二叉树中值相同）
//方法一（拆解子问题） 
//int TreeVal(struct TreeNode* root)
//{
//    return root->val;
//}
//
//bool isUnivalTree(struct TreeNode* root) {
//
//    if (root == NULL)
//    {
//        return true;
//    }
//
//    if (root->right != NULL &&
//        TreeVal(root) != TreeVal(root->right))
//    {
//        return false;
//    }
//    if (root->left != NULL &&
//        TreeVal(root) != TreeVal(root->left))
//    {
//        return false;
//    }
//
//    return isUnivalTree(root->left) &&
//        isUnivalTree(root->right);
//}

//方法二（遍历二叉树）
//bool TreeVal(struct TreeNode* root, int x)
//{
//    if (root == NULL)
//    {
//        return true;
//    }
//    if (root->val != x)
//    {
//        return false;
//    }
//
//    return TreeVal(root->left, x) && TreeVal(root->right, x);
//}
//
//bool isUnivalTree(struct TreeNode* root) {
//    bool x = TreeVal(root, root->val);
//
//    if (x)
//        return true;
//    else
//        return false;
//}