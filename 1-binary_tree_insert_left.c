#include "binary_trees.h"

/**
 * binary_tree_insert_left - It's inserts a node as left-child of another node
 * @parent: It's pointer to the node to insert the left-child in
 * @value: It's value to store in the new node
 *
 * Return: It's Pointer to the newly created node
 *         NULL on failure
 *         NULL if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nw;

	if (!parent)
		return (NULL);

	nw = malloc(sizeof(binary_tree_t));
	if (!nw)
		return (NULL);

	nw->n = value;
	nw->parent = parent;
	nw->right = NULL;
	nw->left = parent->left;
	parent->left = nw;
	if (nw->left)
		nw->left->parent = nw;
	return (nw);
}
