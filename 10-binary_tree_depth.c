#include "binary_trees.h"

/**
 * binary_tree_depth - It's measures the depth of a node in a binary tree
 * @tree: It's node to calculate the depth of
 *
 * Return: It's depth of the node
 *         It's 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		d++;
		tree = tree->parent;
	}

	return (d);
}
