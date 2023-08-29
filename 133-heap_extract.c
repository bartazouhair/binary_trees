#include "binary_trees.h"
#include <stdlib.h>

/**
 * treeHeight - It's measures the height of a binary tree
 * @tree: It's pointer to oot node of Tree to measure the height
 *
 * Return: It's Height or 0 if tree is NULL
 */
size_t treeHeight(const heap_t *tree)
{
	size_t height_ll = 0;
	size_t height_rr = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_ll = 1 + treeHeight(tree->left);

	if (tree->right)
		height_rr = 1 + treeHeight(tree->right);

	if (height_ll > height_rr)
		return (height_ll);
	return (height_rr);
}
/**
 * treeSize_h - It's measures the sum of heights of a binary tree
 * @tree: It's pointer to oot node of tree to measure the height
 *
 * Return: It's Height or 0 if tree is NULL
 */
size_t treeSize_h(const binary_tree_t *tree)
{
	size_t height_ll = 0;
	size_t height_rr = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_ll = 1 + treeSize_h(tree->left);

	if (tree->right)
		height_rr = 1 + treeSize_h(tree->right);

	return (height_ll + height_rr);
}

/**
 * preOrder - It's goes through a binary tree using pre-order traversal
 * @tree: It's pointer to root node of tree to traverse
 * @node: It's will be last note in traverse
 * @height: It's height of tree
 *
 * Return: It's No Return
 */
void preOrder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	preOrder(tree->left, node, height);
	preOrder(tree->right, node, height);
}

/**
 * heapify - It's heapifies max binary heap
 * @root: It's pointer to binary heap
 */
void heapify(heap_t *root)
{
	int vle;
	heap_t *t1, *t2;

	if (!root)
		return;

	t1 = root;

	while (1)
	{
		if (!t1->left)
			break;
		if (!t1->right)
			t2 = t1->left;
		else
		{
			if (t1->left->n > t1->right->n)
				t2 = t1->left;
			else
				t2 = t1->right;
		}
		if (t1->n > t2->n)
			break;
		vle = t1->n;
		t1->n = t2->n;
		t2->n = vle;
		t1 = t2;
	}
}

/**
 * heap_extract - It's extracts the root node from a Max Binary Heap
 * @root: It's pointer to the heap root
 * Return: It's value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int vle;
	heap_t *heap_rr, *node;

	if (!root || !*root)
		return (0);
	heap_rr = *root;
	vle = heap_rr->n;
	if (!heap_rr->left && !heap_rr->right)
	{
		*root = NULL;
		free(heap_rr);
		return (vle);
	}

	preOrder(heap_rr, &node, treeHeight(heap_rr));

	heap_rr->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_rr);
	*root = heap_rr;
	return (vle);
}
