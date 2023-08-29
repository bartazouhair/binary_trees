#include "binary_trees.h"

/**
 * array_to_heap - It's builds a Max Binary Heap tree from an array
 * @array: It's Pointer to irst element of array to be converted
 * @size: It's the number of element in the array
 *
 * Return: It's a pointer to the root node of the created Binary Heap
 *         NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int a;
	heap_t *rt = NULL;

	for (a = 0; a < size; a++)
		heap_insert(&rt, array[a]);

	return (rt);
}
