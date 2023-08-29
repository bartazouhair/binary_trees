#include "binary_trees.h"

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
 * binary_tree_balance - It's measures the balance factor of a binary tree
 * @tree: Its pointer to Root node of Tree to measure the balance factor
 *
 * Return: It's the balance factor
 *         0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_ll, height_rr;

	if (!tree)
		return (0);

	height_ll = tree->left ? (int)binary_tree_height(tree->left) : -1;
	height_rr = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (height_ll - height_rr);
}
