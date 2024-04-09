#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Build an AVL tree from a sorted array
 * @array: pointer first element of array
 * @size: number elements in array
 * Return: pointer to root node of the create AVL tree or Null
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL || size < 1)
		return (NULL);

	/* recursive helper function */
	root = create_avl_node(array, 0, size - 1, NULL);

	return (root);
}

/**
 * create_avl_node - Create an AVL node from a sorted array
 * @array: pointer first element array
 * @start: start idx of subarray
 * @end: end idx of subarray
 * @parent: parent node
 * Return: Pointer to created node or NULL
 */
avl_t *create_avl_node(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *node;

	if (array == NULL || start > end)
		return (NULL);


	/* calculate middle idx */
	mid = (start + end) / 2;
	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->n = array[mid];
	node->parent = parent;
	node->right = create_avl_node(array, mid + 1, end, node);
	node->left = create_avl_node(array, start, mid - 1, node);

	return (node);
}
