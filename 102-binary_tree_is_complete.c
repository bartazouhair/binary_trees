#include "binary_trees.h"

/**
 * bticHelper - It's a checks if a binary tree is complete
 * @tree: It's a pointer to the root node of the tree to check
 * @index: It's node index to check
 * @size: It's number of nodes in the tree
 *
 * Return: It's 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int bticHelper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (bticHelper(tree->left, 2 * index + 1, size) &&
		bticHelper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - It's a measures the size of a binary tree
 * @tree: It's tree to measure the size of
 *
 * Return: It's size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_is_complete - It's checks if a binary tree is complete
 * @tree: It's a pointer to the root node of the tree to check
 *
 * Return: It's 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t sz;

	if (!tree)
		return (0);
	sz = binary_tree_size(tree);

	return (bticHelper(tree, 0, sz));
}
