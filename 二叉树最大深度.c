int maxDepth(struct TreeNode* root){
    if (root == NULL)
    {
        return 0;
    }

    int left = 1 + maxDepth(root->left);
    int right = 1 + maxDepth(root->right);

    return left > right ? left : right;
}