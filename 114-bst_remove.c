#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the desired
 * value, or NULL on failure
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL;

	if (!root)
		return (NULL);
	node = bst_search(root, value);
	if (!node)
		return (NULL);
	if (!node->left && !node->right)
	{
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = NULL;
			else
				node->parent->right = NULL;
		}
		free(node);
		return (root);
	}
	if (node->left && node->right)
	{
		node = node->right;
		while (node->left)
			node = node->left;
		node->parent->left = node->right;
		if (node->right)
			node->right->parent = node->parent;
		node->parent = NULL;
		node->left = root->left;
		node->right = root->right;
		if (root->left)
			root->left->parent = node;
		if (root->right)
			root->right->parent = node;
		free(root);
		return (node);
	}
	if (node->left)
	{
		node->left->parent = node->parent;
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = node->left;
			else
				node->parent->right = node->left;
		}
		else
			root = node->left;
	}
	else
	{
		node->right->parent = node->parent;
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = node->right;
			else
				node->parent->right = node->right;
		}
		else
			root = node->right;
	}
	free(node);
	return (root);

}

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing a value equals to value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
