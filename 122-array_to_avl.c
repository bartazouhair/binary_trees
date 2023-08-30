#include "binary_trees.h"

/**
* array_to_avl - It's builds an AVL tree from an array.
* @array: It's pointer to first element of the array to be converted.
* @size:  It's number of element in the array.
* Return: It's pointer to root node of the created AVL tree, or NULL on fail
*/
avl_t *array_to_avl(int *array, size_t size)
{
	size_t m;
	avl_t *tre = NULL;

	if (!array)
		return (NULL);

	for (m = 0; m < size; m++)
		avl_insert(&tre, array[m]);

	return (tre);
}
