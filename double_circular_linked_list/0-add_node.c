#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/**
 * add_node_end - Adds a new node at the end of a doubly linked list
 * @list: The list to modify
 * @str: The string to copy into the new node
 * Return: The address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
List *new_node, *last;

if (list == NULL)
return (NULL);

new_node = malloc(sizeof(List));
if (new_node == NULL)
return (NULL);

new_node->str = str;
if (*list == NULL)
{
*list = new_node;
new_node->prev = new_node;
new_node->next = new_node;
}
else
{
last = (*list)->prev;
last->next = new_node;
new_node->prev = last;
new_node->next = *list;
(*list)->prev = new_node;
}
return (new_node);
}

/**
 * add_node_begin - Adds a new node at the beginning of a doubly linked list
 * @list: The list to modify
 * @str: The string to copy into the new node
 * Return: The address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
List *new_node, *last;

if (list == NULL)
return (NULL);

new_node = malloc(sizeof(List));
if (new_node == NULL)
return (NULL);

new_node->str = str;
if (*list == NULL)
{
*list = new_node;
new_node->prev = new_node;
new_node->next = new_node;
}
else
{
last = (*list)->prev;
new_node->prev = last;
new_node->next = *list;
(*list)->prev = new_node;
last->next = new_node;
*list = new_node;
}
return (new_node);
}
