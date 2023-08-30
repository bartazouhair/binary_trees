#include "binary_trees.h"

/**
 * treeSize - It's measures the sum of heights of a binary tree
 * @tree: It's pointer to root node of the tree to measure the height
 *
 * Return: It's Height or 0 if tree is NULL
 */
size_t treeSize(const binary_tree_t *tree)
{
	size_t height_ll = 0;
	size_t height_rr = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_ll = 1 + treeSize(tree->left);

	if (tree->right)
		height_rr = 1 + treeSize(tree->right);

	return (height_ll + height_rr);
}

/**
 * heap_to_sorted_array - It's converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: It's pointer to root node of the heap to convert
 * @size: It's address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int j, *m = NULL;

	if (!heap || !size)
		return (NULL);

	*size = treeSize(heap) + 1;

	m = malloc(sizeof(int) * (*size));

	if (!m)
		return (NULL);

	for (j = 0; heap; j++)
		a[j] = heap_extract(&heap);

	return (m);
}
