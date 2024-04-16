#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer head of the skip list
 * @value: searched value
 *
 * Return: Pointer to the first node where the value is located
 *		   NULL if failure
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list;
	skiplist_t *express_ptr = NULL;

	if (!list)
		return (NULL);
	while (current->express)
	{
		express_ptr = current->express;
		printf("Value checked at index [%lu] = [%d]\n",
				express_ptr->index, express_ptr->n);

		if (express_ptr->n >= value)
			break;

		current = express_ptr;
}

printf("Value found between indexes [%lu] and [%lu]\n",
			current->index, express_ptr->index);

	while (current != express_ptr)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);

		if (current->n == value)
			return (current);
		else if (current->n > value)
			return (NULL);

		current = current->next;
	}
	return (NULL);
}
