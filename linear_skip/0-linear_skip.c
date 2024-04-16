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
	skiplist_t *express_ptr;

	if (!list)
		return (NULL);

	express_ptr = list->express;
	printf("Value checked at index [%lu] = [%d]\n",
			express_ptr->index, express_ptr->n);
	while (express_ptr != NULL && express_ptr->n < value)
	{
		list = express_ptr;
		express_ptr = express_ptr->express;
		if (express_ptr == NULL)
			break;
		printf("Value checked at index [%lu] = [%d]\n",
				express_ptr->index, express_ptr->n);
	}
	if (express_ptr == NULL)
	{
		express_ptr = list;
		while (express_ptr->next != NULL)
			express_ptr = express_ptr->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			list->index, express_ptr->index);
	while (list != NULL && list->n <= express_ptr->n)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index,
		       list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

return (NULL);
}
