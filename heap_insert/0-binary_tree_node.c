#include <stdlib.h>
<<<<<<< HEAD
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
=======
#include "lists.h"

/**
 * insert_node - insert a new node into a sorted linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be insert in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;
    
    current = *head;

new = malloc(sizeof(listint_t));
if (new == NULL)
    return (NULL);

new->n = number;

while (current && current->next && number > current->next->n)
    current = current->next;

if ((current == NULL) || (current->n > number))
{
    new->next = *head;
    *head = new;
}
else
{
    new->next = current->next;
    current->next = new;
}
return (new);
>>>>>>> origin/main
}
