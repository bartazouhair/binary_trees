#include "binary_trees.h"

/**
 * bstMinVal - It's finds smallest node from Binary Search Tree
 * @rt: It's a pointer to the root node of the tree
 * Return: It's a pointer to the smallest node
 */
bst_t *bstMinVal(bst_t *rt)
{
	bst_t *mn = rt;

	while (mn->left)
		mn = mn->left;

	return (mn);
}

/**
 * bst_remove - It's removes a node from a Binary Search Tree
 * @root: It's a pointer to root node of the tree where you will remove a node
 * @value: It's the value to remove in the tree
 * Return: It"s a pointer to new root node of the tree after removal
 *         NULL on failure
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			tp = root->right;
			free(root);
			return (tp);
		}
		else if (!root->right)
		{
			tp = root->left;
			free(root);
			return (tp);
		}
		tp = bstMinVal(root->right);
		root->n = tp->n;
		root->right = bst_remove(root->right, tp->n);
	}
	return (root);
}
