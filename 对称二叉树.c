struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    invertTree(root->left);
    invertTree(root->right);

    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL)
    {
        return true;
    }

    if(p == NULL || q == NULL)
    {
        return false;
    }

    if(p->val != q->val)
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}

bool isSymmetric(struct TreeNode* root){
    
    invertTree(root->right);

    return isSameTree(root->left, root->right);
}