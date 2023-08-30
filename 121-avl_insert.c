#include "binary_trees.h"

/**
* ARGL - It's todo.
* @tree: It's todo.
* @value: It's todo.
*/
void ARGL(avl_t **tree, int value)
{
	int m;

	m = binary_tree_balance(*tree);
	if (m > 1)
	{
		if (value < (*tree)->left->n)
		{
			*tree = binary_tree_rotate_right(*tree);
			return;
		}
		if (value > (*tree)->left->n)
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			*tree = binary_tree_rotate_right(*tree);
			return;
		}
	}
	if (m < -1)
	{
		if (value > (*tree)->right->n)
		{
			*tree = binary_tree_rotate_left(*tree);
			return;
		}
		if (value < (*tree)->right->n)
		{
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
			*tree = binary_tree_rotate_left(*tree);
			return;
		}
	}
}

/**
* avlAux - It's inserts a value in an AVL Tree.
* @tree: It's pointer to root of the AVL tree for inserting the value.
* @value: It's value to store in node to be inserted.
* Return: It's pointer to the created node, or NULL on failure.
*/
avl_t *avlAux(avl_t **tree, int value)
{
	avl_t *ndo;

	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			ndo = avlAux(&((*tree))->left, value);
			if (ndo)
				ARGL(tree, value);
			return (ndo);
		}
	}
	if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
		{
			ndo = avlAux(&((*tree))->right, value);
			if (ndo)
			{
				ARGL(tree, value);
				return (ndo);
			}
		}
	}
	return (NULL);
}

/**
* avl_insert - It's inserts a value in an AVL Tree.
* @tree: It's double pointer to root of the AVL tree for inserting the value.
* @value:  It's value to store in the node to be inserted.
* Return: It's pointer to the created node, or NULL on failure.
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = (avl_t *)binary_tree_node(NULL, value);
		return (*tree);
	}
	return (avlAux(tree, value));
}
