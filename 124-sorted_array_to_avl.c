#include "binary_trees.h"

/**
 * sataHelper - It's helper that builds an AVL tree from an array
 * @root: It's double pointer to the root node of the subtree
 * @array: It's a pointer to the first element of the array to be converted
 * @mn: It's lower bound index
 * @mx: It's upper bound index
 */
void sataHelper(avl_t **root, int *array, size_t mn, size_t mx)
{
	avl_t *nw = NULL;
	size_t mdl;

	if (mx - mn > 1)
	{
		mdl = (mx - mn) / 2 + mn;
		nw = binary_tree_node(*root, array[mdl]);
		if (array[mdl] > (*root)->n)
			(*root)->right = nw;
		else if (array[mdl] < (*root)->n)
			(*root)->left = nw;
		sataHelper(&nw, array, mn, mdl);
		sataHelper(&nw, array, mdl, mx);
	}
}

/**
 * sorted_array_to_avl - It's builds an AVL tree from an array
 * @array: It's a pointer to the first element of the array to be converted
 * @size: It's number of elements in the array
 *
 * Return: It's a pointer to the root node of the created AVL tree
 *         NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *trr = NULL;
	size_t mdl;

	if (!array)
		return (NULL);
	mdl = (size - 1) / 2;
	trr = binary_tree_node(NULL, array[mdl]);

	sataHelper(&trr, array, -1, mdl);
	sataHelper(&trr, array, mdl, size);

	return (trr);
}
