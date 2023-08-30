#include "binary_trees.h"

size_t heiGht(const binary_tree_t *tree);
int baLance(const binary_tree_t *tree);
avl_t *avlInsertRecursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * heiGht - It's Measures the heiGht of a binary tree.
 * @tree: It's A pointer to root node of the tree to measure the heiGht.
 *
 * Return: It's If tree is NULL,function must return 0 else return heiGht.
 */
size_t heiGht(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t ll = 0, rr = 0;

		ll = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		rr = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((ll > rr) ? ll : rr);
	}
	return (0);
}

/**
 * baLance - It's Measures the baLance factor of a binary tree.
 * @tree: It's A pointer root node of tree to measure the baLance
 *
 * Return: its If is NULL return 0 else return baLanc
 */
int baLance(const binary_tree_t *tree)
{
	return (tree != NULL ? heiGht(tree->left) - heiGht(tree->right) : 0);
}

/**
 * avlInsertRecursive - Its Inserts value into an AVL tree recursively.
 * @tree: It's A double pointer root node of the AVL tree insert into.
 * @prt: It's The parent node of the current working node.
 * @nw: It's A double pointer to store the new node.
 * @val: It's The value to insert into the AVL tree.
 *
 * Return: It's A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avlInsertRecursive(avl_t **tree, avl_t *prt,
		avl_t **nw, int val)
{
	int bfc;

	if (*tree == NULL)
		return (*nw = binary_tree_node(prt, val));

	if ((*tree)->n > val)
	{
		(*tree)->left = avlInsertRecursive(&(*tree)->left, *tree, nw, val);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < val)
	{
		(*tree)->right = avlInsertRecursive(&(*tree)->right, *tree, nw, val);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bfc = baLance(*tree);
	if (bfc > 1 && (*tree)->left->n > val)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfc < -1 && (*tree)->right->n < val)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfc > 1 && (*tree)->left->n < val)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfc < -1 && (*tree)->right->n > val)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - It's Inserts a value into an AVL tree.
 * @tree: It's A double pointer to root node of the AVL tree insert into.
 * @value: It's The value to insert into the AVL tree.
 *
 * Return: It's A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avlInsertRecursive(tree, *tree, &new, value);
	return (new);
}
