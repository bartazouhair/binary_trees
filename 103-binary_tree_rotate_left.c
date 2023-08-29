#include "binary_trees.h"

/**
 * binary_tree_rotate_left - It's a performs a left-rotation on a binary tree
 * @tree: It's a pointer to the root node of the tree to check
 *
 * Return: It's Pointer to the new root node of the tree once rotated
 *         NULL upon failure
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tp = NULL, *prt;

	if (!tree || !tree->right)
		return (NULL);
	tp = tree;
	prt = tree->prt;
	tree = tree->right;
	tree->prt = NULL;
	if (tree->left)
	{
		tp->right = tree->left;
		tree->left->prt = tp;
	}
	else
		tp->right = NULL;
	tp->prt = tree;
	tree->left = tp;
	if (prt)
		prt->right = tree;
	tree->prt = prt;
	return (tree);
}
