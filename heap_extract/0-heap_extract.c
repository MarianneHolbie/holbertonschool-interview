#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * heapify - rebuild tree
 * @root: root
 * @node: node
*/
void heapify(heap_t **root, heap_t *node)
{
if (!node)
return;

heap_t *largest = node;
heap_t *left = node->left;
heap_t *right = node->right;

/* Find biggest node and its child */
if (left && left->n > largest->n)
largest = left;
if (right && right->n > largest->n)
largest = right;

/* if the biggest is not the current */
if (largest != node)
{
/* swap */
int temp = node->n;
node->n = largest->n;
largest->n = temp;

/* repeat process*/
heapify(root, largest);
}
}

/**
 * deleteNode - delate last node
 * @root: pointer node to delete
 * @node: pointer to node for replace
*/
void deleteNode(heap_t *root, heap_t *node)
{
if (!root || !node)
return;

/* node is a leaf*/
if (!node->left && !node->right)
{
if (node->parent && node->parent->left == node)
node->parent->left = NULL;
else if (node->parent && node->parent->right == node)
node->parent->right = NULL;
}

/* node add one child*/
else if (!node->left || !node->right)
{
heap_t *child = node->left ? node->left : node->right;
if (node->parent)
{
if (node->parent->left == node)
node->parent->left = child;
else
node->parent->right = child;
}
child->parent = node->parent;
}

/* node add 2 child*/
else
{
heap_t *successor = findMinNode(node->right);
node->n = successor->n;
deleteNode(root, successor);
}
}


/**
 * findLastNode - find last node in order level
 * @root: pointer to the root node of the MAx Binary Heap
 * Return: last node
*/
heap_t *findLastNode(heap_t *root)
{
if (!root)
return (NULL);

heap_t *queue[1000];
int front = 0, rear = 0;

queue[rear++] = root;
while (front != rear)
{
heap_t *curr = queue[front++];

/* add child to the queue*/
if (curr->left)
queue[rear++] = curr->left;
if (curr->right)
queue[rear++] = curr->right;
}

return (queue[rear - 1]);

}


/**
 * findMinNode - fin node with minest value
 * @root: root of node
 * return: min node
*/
heap_t *findMinNode(heap_t *root)
{
if (!root)
return (NULL);

heap_t *curr = root;
while (curr->left)
curr = curr->left;

return (curr);
}


/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
int root_value;

if (!root || !(*root))
return (0);

/* Store root value */
root_value = (*root)->n;

/* Find last order node */
heap_t *lastNode = findLastNode(*root);

/* replace root by value last order node*/
(*root)->n = lastNode->n;

/* supress last node*/
deleteNode(*root, lastNode);

/* reconstruct tree*/
heapify(root, *root);

/*free last node initial*/
free(lastNode);

return (root_value);
}
