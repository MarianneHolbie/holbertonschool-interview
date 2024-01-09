#include <stdio.h>
#include <stdlib.h>
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
listint_t *current = *head;

new = malloc(sizeof(listint_t));
if (new == NULL)
return (NULL);

new->n = number;
new->next = NULL;

if (*head == NULL || number < current->n)
{
new->next = *head;
*head = new;
return new;
}

while (current->next && number > current->next->n)
{
current = current->next;
}

new->next = current->next;
current->next = new;

return (new);
}
