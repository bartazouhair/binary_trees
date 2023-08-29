#include "binary_trees.h"

/**
 * binary_tree_leaves - It's counts the leaves in a binary tree
 * @tree: It's tree to count the leaves from
 *
 * Return: It's number of leaves
 *         It's 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lvs = 0;

	if (tree)
	{
		lvs += (!tree->left && !tree->right) ? 1 : 0;
		lvs += binary_tree_leaves(tree->left);
		lvs += binary_tree_leaves(tree->right);
	}
	return (lvs);
}
