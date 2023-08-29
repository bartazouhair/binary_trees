#include "binary_trees.h"

/**
 * binary_tree_depth - It's a measures the depth of a node in a binary tree
 * @tree: It's node to calculate the depth of
 *
 * Return: It's depth of the node
 *         0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		d++;
		tree = tree->parent;
	}

	return (d);
}

/**
 * binary_trees_ancestor - It's finds the lowest common ancestor of two nodes
 * @first: It's a pointer to the first node to find the ancestor
 * @second: It's a pointer to the second node to find the ancestor
 *
 * Return: It's pointer to the ancestor node
 *         NULL if there is no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t df, ds;

	if (!first || !second)
		return (NULL);

	df = binary_tree_depth(first);
	ds = binary_tree_depth(second);

	while (df > ds)
	{
		first = first->parent;
		df--;
	}
	while (ds > df)
	{
		second = second->parent;
		ds--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
