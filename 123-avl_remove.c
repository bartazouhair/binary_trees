#include "binary_trees.h"

/**
 * baal - It's Measures balance factor of a AVL
 * @tree: It's tree to go through
 * Return: It's balanced factor
 */
void baal(avl_t **tree)
{
	int bvl;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	baal(&(*tree)->left);
	baal(&(*tree)->right);
	bvl = binary_tree_balance((const binary_tree_t *)*tree);
	if (bvl > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bvl < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * succeSsor - It's get Next succeSsor mean Min node in the right subtree
 * @node: It's tree to check
 * Return: It's the min value of this tree
 */
int succeSsor(bst_t *node)
{
	int lf = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		lf = succeSsor(node->left);
		if (lf == 0)
		{
			return (node->n);
		}
		return (lf);
	}

}
/**
 *removeType - It's function that removes a node depending of its children
 *@root: It's node to remove
 *Return: It's 0 if it has no children or other value if it has
 */
int removeType(bst_t *root)
{
	int nv = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		nv = succeSsor(root->right);
		root->n = nv;
		return (nv);
	}
}
/**
 * bst_remove - It's remove a node from a BST tree
 * @root: It's root of the tree
 * @value: It's node with this value to remove
 * Return: It's the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int tp = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		tp = removeType(root);
		if (tp != 0)
			bst_remove(root->right, tp);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - It's remove a node from a AVL tree
 * @root: It's root of the tree
 * @value: It's node with this value to remove
 * Return: It's the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	baal(&root_a);
	return (root_a);
}
