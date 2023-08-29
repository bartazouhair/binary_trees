#include "binary_trees.h"

/**
 * btloHelper - It's goes through a binary tree using post-order traverse
 * @tree: It's tree to traverse
 * @func: It's pointer to a function to call for each node
 * @level: It's the level of the tree to call func upon
 */
void btloHelper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		btloHelper(tree->left, func, level - 1);
		btloHelper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - It's measures the height of a binary tree
 * @tree: It's tree to measure the height of
 *
 * Return: It's height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_ll = 0;
	size_t height_rr = 0;

	if (!tree)
		return (0);

	height_ll = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_rr = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_ll > height_rr ? height_ll : height_rr);
}

/**
 * binary_tree_levelorder - Its a binary tree with  level-order traverse
 * @tree: It's tree to traverse
 * @func: It's pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t l, ml;

	if (!tree || !func)
		return;

	ml = binary_tree_height(tree) + 1;

	for (l = 1; l <= ml; l++)
		btloHelper(tree, func, l);
}
