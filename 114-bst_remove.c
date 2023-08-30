#include "binary_trees.h"

/**
* menorElemento - It's todo.
* @nd: It's todo.
* Return: It's todo.
*/
bst_t *menorElemento(bst_t *nd)
{
	while (nd->left)
		nd = nodo->left;
	return (nd);

}

/**
 * bst_remove - It's Remove a node from a binary search tree
 * @root: It's Pointer to the root of the tree
 * @value: It's The value to remove
 *
 * Return: It's A pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *hld = NULL;

	if (!root)
		return (NULL);

	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else
		if (root->n < value)
			root->right = bst_remove(root->right, value);
		else
		{
			if (root->left && root->right)
			{
				hld = menorElemento(root->right);
				root->n = hld->n;
				root->right = bst_remove(root->right, hld->n);
			}
			else
			{
				if (!root->left && !root->right)
				{
					free(root);
					return (NULL);
				}
				hld = root;
				if (!root->left)
					root = root->right;
				else
					if (!root->right)
						root = root->left;
				if (hld->parent->left == hld)
					hld->parent->left = root;
				else
					hld->parent->right = root;
				root->parent = hld->parent;
				free(hld);
			}
		}
	return (root);
}
