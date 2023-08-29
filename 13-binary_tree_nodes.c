#include "binary_trees.h"

/**
 * binary_tree_size - It's measures the size of a binary tree
 * @tree: It's tree to measure the size of
 *
 * Return: It's size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_leaves - It's counts the leaves in a binary tree
 * @tree: It's tree to count the leaves from
 *
 * Return: It's number of leaves
 *         It's 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

/**
 * binary_tree_nodes - Its counts Nodes with at least 1 child in a binary tree
 * @tree: It's tree to count the nodes from
 *
 * Return: It's number of nodes counted
 *         0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if ((!tree->left && !tree->right) || !tree)
		return (0);

	return (binary_tree_size(tree) - binary_tree_leaves(tree));
}
