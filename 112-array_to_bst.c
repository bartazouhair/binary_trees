#include "binary_trees.h"

/**
 * array_to_bst - It's a builds a Binary Search Tree from an array
 * @array: It's a pointer to the first element of the array to be converted
 * @size: It's the number of elements in the array
 * Return: It's A pointer to the root node of the created BST
 *         NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int z;
	bst_t *rt = NULL;

	for (z = 0; z < size; z++)
		bst_insert(&rt, array[z]);

	return (rt);
}
