#include "binary_trees.h"

/**
 * binary_tree_height - It's measures the height of a binary tree
 * @tree: It's tree to measure the height of
 *
 * Return: It's height of the tree
 *         It's 0 if tree is NULL
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
