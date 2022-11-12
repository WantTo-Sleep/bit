int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = 1 + maxDepth(root->left);
    int right = 1 + maxDepth(root->right);

    return left > right ? left : right;
}

bool isBalanced(struct TreeNode* root)
{
    if (root == NULL)
    {
        return true;
    }

    if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
    {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}
