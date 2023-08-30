#include "binary_trees.h"

/**
 * heap_to_sorted_array - It's Converts a Binary Max Heap to a sorted array.
 * @heap: It's Pointer to root node of the heap to convert.
 * @size: It's Address to store the size of the array.
 *
 * Return: It's Pointer to the sorted array, NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sr;
	size_t m;

	if (!heap || !size)
		return (NULL);

	*size = binary_tree_size(heap);
	sr = malloc(*size * sizeof(int));
	if (!sr)
		return (NULL);

	for (m = 0; m < *size; m++)
	{
		sr[m] = heap->n;
		heap->n = heap_extract(&heap);
	}
	return (sr);
}
