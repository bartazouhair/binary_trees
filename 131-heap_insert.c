#include "binary_trees.h"

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
 * heap_insert - It's inserts a value in Max Binary Heap
 * @root: Its a double pointer to Root node of Heap to insert the value
 * @value: It's the value to store in the node to be inserted
 *
 * Return: It's a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *trr, *nw, *fp;
	int sz, lvs, sb, bt, lv, tp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	trr = *root;
	sz = binary_tree_size(trr);
	lvs = sz;
	for (lv = 0, sb = 1; lvs >= sb; sb *= 2, lv++)
		lvs -= sb;
	for (bt = 1 << (lv - 1); bt != 1; bt >>= 1)
		trr = lvs & bt ? trr->right : trr->left;
	nw = binary_tree_node(trr, value);
	lvs & 1 ? (trr->right = nw) : (trr->left = nw);
	fp = nw;
	for (; fp->parent && (fp->n > fp->parent->n); fp = fp->parent)
	{
		tp = fp->n;
		fp->n = fp->parent->n;
		fp->parent->n = tp;
		nw = nw->parent;
	}
	return (nw);
}
