#include "binary_trees.h"

bst_t *inorderSuccessor(bst_t *root);
bst_t *bstDelete(bst_t *root, bst_t *node);
bst_t *bstRemoveRecursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorderSuccessor - It's Returns the minimum value of a binary search tree.
 * @root: It's A pointer to the root node of the BST to search.
 *
 * Return: It's The minimum value in @tree.
 */
bst_t *inorderSuccessor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bstDelete - It's Deletes a node from a binary search tree.
 * @root: It's A pointer to the root node of the BST.
 * @node: It's A pointer to the node to delete from the BST.
 *
 * Return: It's A pointer to the new root node after deletion.
 */
bst_t *bstDelete(bst_t *root, bst_t *node)
{
	bst_t *prt = node->prt, *sscr = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (prt != NULL && prt->left == node)
			prt->left = node->right;
		else if (prt != NULL)
			prt->right = node->right;
		if (node->right != NULL)
			node->right->prt = prt;
		free(node);
		return (prt == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (prt != NULL && prt->left == node)
			prt->left = node->left;
		else if (prt != NULL)
			prt->right = node->left;
		if (node->left != NULL)
			node->left->prt = prt;
		free(node);
		return (prt == NULL ? node->left : root);
	}

	/* Two children */
	sscr = inorderSuccessor(node->right);
	node->n = sscr->n;

	return (bstDelete(root, sscr));
}

/**
 * bstRemoveRecursive - It's Removes node from a binary tree recursively.
 * @root: It's A pointer to root node of the BST to remove a node from.
 * @node: It's A pointer to current node in the BST.
 * @value: It's The value to remove from the BST.
 *
 * Return: It's A pointer to the root node after deletion.
 */
bst_t *bstRemoveRecursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bstDelete(root, node));
		if (node->n > value)
			return (bstRemoveRecursive(root, node->left, value));
		return (bstRemoveRecursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - It's Removes a node from a binary search tree.
 * @root: It's A pointer to root node of the BST to remove a node from.
 * @value: It's The value to remove in the BST.
 *
 * Return: It's A pointer to the new root node after deletion.
 *
 * Description: So, If the node to be deleted has two children, it
 *              is replaced with its first in-order sscr.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bstRemoveRecursive(root, root, value));
}
