#include "binary_trees.h"

/**
 * array_to_avl - It's builds an AVL tree from an array
 * @array: It's array to create from
 * @size: It's size of the array
 *
 * Return: It's a pointer to the root node of the created AVL tree
 *         NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int z;
	avl_t *rt = NULL;

	for (z = 0; z < size; z++)
		avl_insert(&rt, array[i]);

	return (rt);
}
