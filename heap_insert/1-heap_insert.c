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
size_t size;

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
size = binary_tree_size(*root);
parent = get_node_from_index(*root, (int)(size - 1) / 2);

if (parent != NULL)
{
new_node->parent = parent;

if (size % 2 == 0)
parent->right = new_node;
else
parent->left = new_node;

// call function to restore the Max Heap property
heapify_up(new_node);
}
else
{
free(new_node);
return (NULL);
}
return (new_node);
}

/**
 * binary_tree_size - calculate the size of a binary tree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: size of the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
if (tree == NULL)
{
return (0);
}
return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
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

/**
 * get_node_from_index - Get a node from its index in the heap
 * @root: pointer to the root node
 * @idx: indew of the node to search
 *
 * Return: pointer to the node
 */
heap_t *get_node_from_index(heap_t *root, int idx)
{
int parentIdx, direction;

if (idx == 0)
return (root);

parentIdx = (idx - 1) / 2;
direction = (idx - 1) % 2;

if (direction == 0)
{
return (get_node_from_index(root, parentIdx)->left);
}
return (get_node_from_index(root, parentIdx)->right);
}
