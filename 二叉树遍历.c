#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BinaryTreeNode
{
    char val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;

BTNode* BinaryTreeCreate(char* a, int* pi);
void BinaryTreeInOrder(BTNode* root);

int main()
{
    char str[100] = { 0 };
    gets(str);
	int i = 0;

	BTNode* tree = BinaryTreeCreate(str, &i);

	BinaryTreeInOrder(tree);

    return 0;
}

BTNode* BinaryTreeCreate(char* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* tree = (BTNode*)malloc(sizeof(BTNode));
	assert(tree);
	tree->val = a[*pi];
	(*pi)++;

	tree->left = BinaryTreeCreate(a, pi);
	tree->right = BinaryTreeCreate(a, pi);

	return tree;
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreeInOrder(root->left);
	printf("%c ", root->val);
	BinaryTreeInOrder(root->right);
}
