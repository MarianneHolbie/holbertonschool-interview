#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"


/**
 * height- recursiv function calculate height of tree
 * @tree: binary tree to calculate height
 *
 * Return: int height of tree or max beetween left and right node
 */
int height(const binary_tree_t *tree)
{
if (tree == NULL)
return (-1);

int left_height = height(tree->left);
int right_height = height(tree->right);

return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * is_bst- function verify validated BST
 * @tree: tree to test
 * @min: min value
 * @max: max value
 *
 * Return: tree
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
if (tree == NULL)
return (1);

if (tree->n <= min || tree->n >= max)
return (0);

return (is_bst(tree->left, min, tree->n - 1) &&
is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl- recursiv function verify tree is valided AVL
 * @tree: tree to test
 *
 * Return: 0 if not, 1 other
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

/* valid binary tree ? */
if (!is_bst(tree, INT_MIN, INT_MAX))
return (0);

/* balanced AVL */
int left_height = height(tree->left);
int right_height = height(tree->right);

if (abs(left_height - right_height) > 1)
return (0);

/* case One child only */
if (tree->left == NULL || tree->right == NULL)
return (1);

/* recursiv */
return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
