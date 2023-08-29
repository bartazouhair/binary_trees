#include "binary_trees.h"

unsigned char isLeaf(const binary_tree_t *node);
size_t dePth(const binary_tree_t *tree);
const binary_tree_t *getLeaf(const binary_tree_t *tree);
int isPerfectRecursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * isLeaf - It's Checks if a node is a leaf of a binary tree.
 * @node: It's A pointer to the node to check.
 *
 * Return: It's If the node is a leaf, 1, otherwise, 0.
 */
unsigned char isLeaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * dePth - It's Returns the depth of a given
 *         node in a binary tree.
 * @tree: It's A pointer to the node to measure the depth of.
 *
 * Return: It's The depth of node.
 */
size_t dePth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + dePth(tree->parent) : 0);
}

/**
 * getLeaf - It's Returns a leaf of a binary tree.
 * @tree: It's A pointer to the root node of the tree to find a leaf in.
 *
 * Return: It's A pointer to the first encountered leaf.
 */
const binary_tree_t *getLeaf(const binary_tree_t *tree)
{
	if (isLeaf(tree) == 1)
		return (tree);
	return (tree->left ? getLeaf(tree->left) : getLeaf(tree->right));
}

/**
 * isPerfectRecursive - It's Checks if a binary tree is perfect recursively.
 * @tree: It's A pointer to the root node of the tree to check.
 * @leaf_depth: It's The depth of one leaf in the binary tree.
 * @level: It's Level of current node.
 *
 * Return: It's If the tree is perfect, 1, otherwise 0.
 */
int isPerfectRecursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t lvl)
{
	if (isLeaf(tree))
		return (lvl == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (isPerfectRecursive(tree->left, leaf_depth, lvl + 1) &&
			  isPerfectRecursive(tree->right, leaf_depth, lvl + 1));
}

/**
 * binary_tree_is_perfect - It's Checks if a binary tree is perfect.
 * @tree: It's A pointer to the root node of the tree to check.
 *
 * Return: It's If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (isPerfectRecursive(tree, dePth(getLeaf(tree)), 0));
}
