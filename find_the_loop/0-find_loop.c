#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 *
 * Return: The address of the node where the loop starts, or NULL if there is
 * no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
if (head == NULL)
return (NULL);

listint_t *slow, *fast;

slow = fast = head;

/* Search for loop using fast and slow pointer*/
while (fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;

/* if detected cycle*/
if (slow == fast)
{
/* find entry point*/
slow = head;
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
return (slow);
}
}

/*If no loop*/
return (NULL);

}
