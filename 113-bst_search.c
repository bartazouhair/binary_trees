#include "binary_trees.h"

/**
 * bst_search - It's searches for a value in a Binary Search Tree
 * @tree: It's a pointer to the root node of the BST to search
 * @value: It's the value to search in the tree
 * Return: It's A pointer to the node containing an int equal to `value`
 *         NULL if tree is NULL
 *         NULL if no match is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *nd = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (nd)
	{
		if (value == nd->n)
			return (nd);
		if (value < nd->n)
			nd = nd->left;
		else if (value > node->n)
			nd = nd->right;
	}

	return (NULL);
}
