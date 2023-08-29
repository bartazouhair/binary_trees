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
	bst_t *tp = *tree;
	bst_t *sd = NULL;
	bst_t *nw = binary_tree_node(NULL, value);

	if (*tree == NULL)
		*tree = nw;

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

/**
 * avl_insert - It's inserts a value in an AVL Tree
 * @tree: It's a double pointer to the root node of the AVL tree
 * @value: It's value to insert
 *
 * Return: It's a pointer to the created node
 *         NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int blc = 0;
	avl_t *nd = bst_insert(tree, value);

	blc = binary_tree_balance(*tree);

	if (blc > 1 && value < nd->left->n)
		return (binary_tree_rotate_right(nd));
	if (blc < -1 && value > nd->right->n)
		return (binary_tree_rotate_left(nd));
	if (blc > 1 && value > nd->left->n)
	{
		nd->left = binary_tree_rotate_left(nd->left);
		return (binary_tree_rotate_right(nd));
	}
	if (blc < -1 && value < nd->right->n)
	{
		nd->right = binary_tree_rotate_right(nd->right);
		return (binary_tree_rotate_left(nd));
	}

	return (nd);
}
