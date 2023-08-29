#include "binary_trees.h"

/**
 * binary_tree_nodes - It's Counts the nodes with at least 1 child in a binary tree.
 * @tree: It's A pointer to root node of tree to count the number of nodes.
 *
 * Return: It's If tree is NULL,function must return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nds = 0;

	if (tree)
	{
		nds += (tree->left || tree->right) ? 1 : 0;
		nds += binary_tree_nodes(tree->left);
		nds += binary_tree_nodes(tree->right);
	}
	return (nds);
}
