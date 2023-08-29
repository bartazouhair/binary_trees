#include "binary_trees.h"

/**
 * binary_tree_is_root - It's checks if a node is a root
 * @node: It's node to check
 *
 * Return: It's 1 if node is a root
 *         It's 0 if not a root
 *         It's 0 if node is NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	else
		return (1);
}
