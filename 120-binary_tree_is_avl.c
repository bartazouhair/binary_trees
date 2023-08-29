#include "binary_trees.h"

/**
 * btiaHelper - It's helper that finds if a binary tree is an avl
 * @tree: It's pointer to the root node of the tree
 * @mn: It's minimum value
 * @mx: It's maximum value
 *
 * Return: It's 1 if tree is avl
 *         0 otherwise
 */
int btiaHelper(const binary_tree_t *tree, int mn, int mx)
{
	int pl, pr;

	if (!tree)
		return (1);
	if (tree->n < mn || tree->n > mx)
		return (0);

	pl = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	pr = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(pl - pr) > 1)
		return (0);

	return (btiaHelper(tree->left, mn, tree->n - 1) &&
		btiaHelper(tree->right, tree->n + 1, mx));
}

/**
 * binary_tree_height - It's measures the height of a binary tree
 * @tree: It's tree to measure the height of
 *
 * Return: It's height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_ll = 0;
	size_t height_rr = 0;

	if (!tree)
		return (0);

	height_ll = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_rr = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_ll > height_rr ? height_ll : height_rr);
}

/**
 * binary_tree_is_avl - It's a finds if a binary tree is an avl
 * @tree: It's pointer to the root node of the tree
 *
 * Return: It's 1 if tree is avl
 *         0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (btiaHelper(tree, INT_MIN, INT_MAX));
}
