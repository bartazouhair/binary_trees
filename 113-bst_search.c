#include "binary_trees.h"

/**
 * bst_search - It's Searches for a value in a binary search tree.
 * @tree: It's A pointer to root node of the BST to search.
 * @value: It's The value to search for in the BST.
 *
 * Return: ItsIf the tree is NULL or the value is not found, NULL.
 *         Otherwise, a pointer to the node containing the value.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
