#include "binary_trees.h"

/**
 * binary_tree_sibling - It's a finds the sibling of a node
 * @node: It's a pointer to the node to find the sibling
 *
 * Return: It's pointer to the sibling node
 *         NULL if node is NULL
 *         NULL if the parent is NULL
 *         NULL if the node has no siblings
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node->parent || !node)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
