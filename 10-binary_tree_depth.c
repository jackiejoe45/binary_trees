#include "binary_trees.h"
/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 * Return: Depth of the node. If tree is NULL, return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_root(tree))
		return (0);
	depth = binary_tree_depth(tree->parent);
	return (depth + 1);
}
