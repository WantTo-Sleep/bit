void Swap(struct TreeNode* root)
{
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    invertTree(root->left);
    invertTree(root->right);

    Swap(root);
    return root;
}