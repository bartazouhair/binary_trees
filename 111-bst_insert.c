#include "binary_trees.h"

/**
 * bst_insert - It's inserts a value in a Binary Search Tree
 * @tree: It's a double pointer to the root node of the BST to insert the value
 * @value: It's the value to store in the node to be inserted
 * Return: It's A pointer to the created node
 *         NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tp = NULL;
	bst_t *sd = NULL;
	bst_t *nw = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	tp = *tree;
	while (tp)
	{
		sd = tp;
		if (value < tp->n)
			tp = tp->left;
		else if (value > tp->n)
			tp = tp->right;
		else if (value == tp->n)
			return (NULL);
	}

	nw = binary_tree_node(NULL, value);
	if (sd == NULL)
		sd = nw;
	else if (value < sd->n)
	{
		sd->left = nw;
		nw->parent = sd;
	}
	else
	{
		sd->right = nw;
		nw->parent = sd;
	}

	return (nw);
}
