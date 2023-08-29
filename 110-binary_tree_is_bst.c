#include "binary_trees.h"

/**
 * btibHelper - It's a checks if a binary tree is a valid Binary Search Tree
 * @tree: It's a pointer to the root node of the tree to check
 * @mn: It's Lower bound of checked nored
 * @mx: It's Upper bound of checked nodes
 *
 * Return: It's 1 if tree is a valid BST
 *         0 otherwise
 */
int btibHelper(const binary_tree_t *tree, int mn, int mx)
{
	if (!tree)
		return (1);

	if (tree->n < mn || tree->n > mx)
		return (0);

	return (btibHelper(tree->left, mn, tree->n - 1) &&
		btibHelper(tree->right, tree->n + 1, mx));
}

/**
 * binary_tree_is_bst - Its checks if a binary tree is valid Binary Search Tree
 * @tree: It's a pointer to the root node of the tree to check
 *
 * Return: It's 1 if tree is a valid BST
 *         0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btibHelper(tree, INT_MIN, INT_MAX));
}
