#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_tt - It's a Stores recursively each level in an array of strings
 *
 * @tree: It's Pointer to the node to print
 * @offset: It's Offset to print
 * @depth: It's Depth of the node
 * @ss: It's Buffer
 *
 * Return: It's The length of printed tree after process
 */
static int print_tt(const binary_tree_t *tree, int offset, int depth, char **ss)
{
	char bb[6];
	int width, left, right, is_left, j;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(bb, "(%03d)", tree->n);
	left = print_tt(tree->left, offset, depth + 1, ss);
	right = print_tt(tree->right, offset + left + width, depth + 1, ss);
	for (j = 0; j < width; j++)
		ss[depth][offset + left + j] = bb[j];
	if (depth && is_left)
	{
		for (j = 0; j < width + right; j++)
			ss[depth - 1][offset + left + width / 2 + i] = '-';
		ss[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (j = 0; j < left + width; j++)
			ss[depth - 1][offset - width / 2 + i] = '-';
		ss[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * __height - It's a Measures the height of a binary tree
 *
 * @tree: It's Pointer to the node to measures the height
 *
 * Return: It's The height of the tree starting at @node
 */
static size_t __height(const binary_tree_t *tree)
{
	size_t height_ll;
	size_t height_rr;

	height_ll = tree->left ? 1 + __height(tree->left) : 0;
	height_rr = tree->right ? 1 + __height(tree->right) : 0;
	return (height_ll > height_rr ? height_ll : height_rr);
}

/**
 * binary_tree_print - It's Prints a binary tree
 *
 * @tree: It's Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **ss;
	size_t h, a, b;

	if (!tree)
		return;
	h = __height(tree);
	ss = malloc(sizeof(*ss) * (h + 1));
	if (!ss)
		return;
	for (a = 0; a < h + 1; a++)
	{
		ss[a] = malloc(sizeof(**ss) * 255);
		if (!ss[a])
			return;
		memset(ss[a], 32, 255);
	}
	print_tt(tree, 0, 0, ss);
	for (a = 0; a < h + 1; a++)
	{
		for (b = 254; b > 1; --b)
		{
			if (ss[a][b] != ' ')
				break;
			ss[a][b] = '\0';
		}
		printf("%s\n", ss[a]);
		free(ss[a]);
	}
	free(ss);
}
