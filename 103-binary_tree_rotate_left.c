#include "binary_trees.h"

/**
 * binary_tree_rotate_left - It's Left-rotates a binary tree.
 * @tree: It's A pointer to the root node of the tree to rotate.
 *
 * Return: It's A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pvt, *tp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pvt = tree->right;
	tp = pvt->left;
	pvt->left = tree;
	tree->right = tp;
	if (tp != NULL)
		tp->parent = tree;
	tp = tree->parent;
	tree->parent = pvt;
	pvt->parent = tp;
	if (tp != NULL)
	{
		if (tp->left == tree)
			tp->left = pvt;
		else
			tp->right = pvt;
	}

	return (pvt);
}
