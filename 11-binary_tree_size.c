#include "binary_trees.h"

/**
 * binary_tree_size - It's measures the size of a binary tree
 * @tree: It's tree to measure the size of
 *
 * Return: It's size of the tree
 *         It's 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
