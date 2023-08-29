#include "binary_trees.h"

/**
 *_powRecursion - It's returns the value of x raised to the power of y
 *@a: It's the value to exponentiate
 *@b: It's the power to raise x to
 *Return: It's a to the power of b, or -1 if b is negative
 */

int _powRecursion(int a, int b)
{
	if (b < 0)
		return (-1);
	if (b == 0)
		return (1);
	else
		return (a * _powRecursion(a, b - 1));

}

/**
 * binary_tree_size - It's measures the size of a binary tree
 * @tree: It's tree to measure the size of
 *
 * Return: It's size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - It's a measures the height of a binary tree
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
 * binary_tree_is_perfect - It's a checks if a binary tree is perfect
 * @tree: It's a pointer to the root node of the tree to check
 *
 * Return: It's 1 if the tree is perfect
 *         0 if the tree is not perfect
 *         0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h = 0;
	size_t n = 0;
	size_t p = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	h = binary_tree_height(tree);
	n = binary_tree_size(tree);

	p = (size_t)_pow_recursion(2, h + 1);
	return (p - 1 == n);
}
