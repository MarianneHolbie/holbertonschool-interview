#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
	struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/* create binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* check binary tree is a valid AVL tree */
int binary_tree_is_avl(const binary_tree_t *tree);

/* auxilary function */
int height(const binary_tree_t *tree);
int is_bst(const binary_tree_t *tree, int min, int max);
void binary_tree_print(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
