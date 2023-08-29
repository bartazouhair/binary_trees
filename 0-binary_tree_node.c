#include "binary_trees.h"

/**
 * binary_tree_node - It's creates a binary tree node
 * @parent: It's pointer to the parent node of the node to create
 * @value: It's value to put in the new node
 *
 * Return: It's Pointer to the newly created node
 *         NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nw;

	nw = malloc(sizeof(binary_tree_t));
	if (!nw)
		return (NULL);
	nw->n = value;
	nw->parent = parent;
	nw->left = NULL;
	nw->right = NULL;
	return (nw);
}
