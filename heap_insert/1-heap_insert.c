#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (root == NULL)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    // Case new node = root
    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    // find the parent using a function
    parent = get_insertion_parent(*root);
    new_node->parent = parent;

    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    // call function to restore the Max Heap property
    heapify_up(new_node);

    return (new_node);
}

/**
 * get_insertion_parent - Finds the parent node for insertion
 * @root: Pointer to the root node of the Heap
 *
 * Return: Pointer to the parent node for insertion
 */
heap_t *get_insertion_parent(heap_t *root)
{
    heap_t *parent;

    if (root == NULL)
        return (NULL);

    parent = root;
    // iteratively traverse the tree to fin a node 
    // with at least one child missing
    while (parent->left != NULL && parent->right != NULL)
    {
        if (binary_tree_is_perfect(parent->left) &&
            !binary_tree_is_perfect(parent->right))
            parent = parent->left;
        else
            parent = parent->right;
    }

    return (parent);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (left_height == right_height);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Height of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (MAX(left_height, right_height) + 1);
}

/**
 * heapify_up - Restores the Max Heap property after insertion
 * @node: Pointer to the inserted node
 */
void heapify_up(heap_t *node)
{
    heap_t *parent;
    int temp;

    if (node == NULL)
        return;

    parent = node->parent;
    // swap the node with its parent if necessary
    // moving up the tree until the property is restored
    while (parent != NULL && node->n > parent->n)
    {
        temp = node->n;
        node->n = parent->n;
        parent->n = temp;

        node = parent;
        parent = node->parent;
    }
}
