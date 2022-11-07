// 求树的节点个数
int treeSize(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + treeSize(root->left) + treeSize(root->right);
}

void preOrderTraversal(struct TreeNode* tree, int* arr, int* pos)
{
    if (tree == NULL)
    {
        return;
    }

    arr[*pos] = tree->val;
    (*pos)++;

    preOrderTraversal(tree->left, arr, pos);
    preOrderTraversal(tree->right, arr, pos);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* arr = (int*)malloc(sizeof(int) * treeSize(root));
    assert(arr);
    *returnSize = 0;
    preOrderTraversal(root, arr, returnSize);

    return arr;
}