#include "binary_trees.h"

/**
 * findNode - It's Finds a node given value in a binary search tree.
 * @root: It's The root of the binary search tree.
 * @value: It's The value of the node.
 * Return: It's A pointer to the found node, otherwise NULL.
 */
bst_t *findNode(bst_t *root, int value)
{
	bst_t *nde = NULL;

	if (root != NULL)
	{
		if (root->left != NULL)
			nde = root->left->parent;
		if ((nde == NULL) && (root->right != NULL))
			nde = root->right->parent;
		while (nde != NULL)
		{
			if (nde->n < value)
				nde = nde->right;
			else if (nde->n > value)
				nde = nde->left;
			else
				break;
		}
	}
	return (nde);
}

/**
 * replaceSuccessor - It's Replaces a node with its inorder \
 * successor in a binary search tree.
 * @node: It's A pointer to the node in the binary search tree.
 *
 * Return: It's A pointer to the node's inorder successor node.
 */
bst_t *replaceSuccessor(bst_t **node)
{
	bst_t *nwNode;

	nwNod = (*node)->right;
	while ((nwNod != NULL) && (nwNod->left != NULL))
		nwNod = nwNod->left;
	if ((nwNod != NULL) && (nwNod == (*node)->right))
	{
		nwNod->parent = (*node)->parent;
		nwNod->left = (*node)->left;
		if ((*node)->left != NULL)
			(*node)->left->parent = nwNod;
		if ((*node)->parent != NULL)
		{
			if ((*node)->parent->left == *node)
				(*node)->parent->left = nwNod;
			if ((*node)->parent->right == *node)
				(*node)->parent->right = nwNod;
		}
	}
	else if (nwNod != NULL)
	{
		nwNod->parent->left = nwNod->right;
		if (nwNod->right != NULL)
			nwNod->right->parent = nwNod->parent;
		nwNod->parent = (*node)->parent;
		nwNod->left = (*node)->left;
		nwNod->right = (*node)->right;
		(*node)->left->parent = nwNod;
		(*node)->right->parent = nwNod;
		if ((*node)->parent != NULL)
		{
			if ((*node)->parent->left == *node)
				(*node)->parent->left = nwNod;
			if ((*node)->parent->right == *node)
				(*node)->parent->right = nwNod;
		}
	}
	return (nwNod);
}

/**
 * bst_remove - It's Removes node given value in a binary search tree.
 * @root: It's The binary search tree.
 * @value: It's The value of the node.
 *
 * Return: It's A pointer to the tree's root node, otherwise NULL.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *nde = NULL, *nwRoot = root, *nwNod = NULL;

	if (nwRoot != NULL)
	{
		nde = findNode(root, value);
		if ((nde != NULL) && (nde->n == value))
		{
			if ((nde->left == NULL) && (nde->right == NULL))
			{
				if (nde->parent != NULL)
				{
					if (nde->parent->left == nde)
						nde->parent->left = NULL;
					if (nde->parent->right == nde)
						nde->parent->right = NULL;
				}
			}
			else if ((nde->left != NULL) ^ (nde->right != NULL))
			{
				nwNod = (nde->left != NULL ? nde->left : nde->right);
				if (nde->parent != NULL)
				{
					if (nde->parent->left == nde)
						nde->parent->left = nwNod;
					else if (nde->parent->right == nde)
						nde->parent->right = nwNod;
				}
				nwNod->parent = nde->parent;
			}
			else
			{
				nwNod = replaceSuccessor(&nde);
			}
			nwRoot = (nde->parent == NULL ? nwNod : root);
			free(nde);
		}
	}
	return (nwRoot);
}
