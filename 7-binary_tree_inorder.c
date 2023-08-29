#include "binary_trees.h"

/**
 * binary_tree_inorder - Its goes through a binary tree with in-order traversal
 * @tree: It's tree to traverse
 * @func: It's pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
