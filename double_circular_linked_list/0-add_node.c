#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Adds a new node at the end of a doubly linked list
 * @list: The list to modify
 * @str: The string to copy into the new node
 * Return: The address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
List *new_node, *end;

if (list == NULL)
return (NULL);

if (!str)
	return (NULL);

new_node = malloc(sizeof(List));
if (!new_node)
return (NULL);

new_node->str = strdup(str);
if (!new_node->str)
return (NULL);

if (*list == NULL)
{
*list = new_node;
new_node->prev = new_node;
new_node->next = new_node;
return (new_node);
}
else
{
end = (*list)->prev;
end->next = new_node;
new_node->prev = end;
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
List *new_node, *end;

if (list == NULL)
return (NULL);

if (!str)
return (NULL);

new_node = malloc(sizeof(List));
if (!new_node)
return (NULL);

new_node->str = strdup(str);
if (!new_node->str)
return (NULL);

if (*list == NULL)
{
*list = new_node;
new_node->prev = new_node;
new_node->next = new_node;
return (new_node);
}
else
{
end = (*list)->prev;
new_node->prev = end;
new_node->next = *list;
end->next = new_node;
(*list)->prev = new_node;
*list = new_node;
}
return (new_node);
}
