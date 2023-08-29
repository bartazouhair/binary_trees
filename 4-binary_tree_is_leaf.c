#include "binary_trees.h"

/**
 * binary_tree_is_leaf - It's checks if a node is a leaf
 * @node: It's node to check
 *
 * Return: It's 1 if node is a leaf
 *         It's 0 if not a leaf
 *         It's 0 if node is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node->left != NULL || node == NULL || node->right != NULL)
		return (0);

	return (1);
}
