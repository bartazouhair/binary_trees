#include "binary_trees.h"

/**
 * binary_tree_rotate_right - It's a performs a right-rotation on a binary tree
 * @tree: It's a pointer to the root node of the tree to check
 *
 * Return: It's Pointer to the new root node of the tree once rotated
 *         NULL upon failure
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tp = NULL, *prt;

	if (!tree || !tree->left)
		return (NULL);
	tp = tree;
	prt = tree->prt;
	tree = tree->left;
	tree->prt = NULL;
	if (tree->right)
	{
		tp->left = tree->right;
		tree->right->prt = tp;
	}
	else
		tp->left = NULL;
	tp->prt = tree;
	tree->right = tp;
	if (prt)
		prt->left = tree;
	tree->prt = prt;
	return (tree);
}
