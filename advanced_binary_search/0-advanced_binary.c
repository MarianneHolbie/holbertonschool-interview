#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"


/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 on failure
 */
int advanced_binary(int *array, size_t size, int value)
{
size_t i, mid;
int ret = -1;

if (array == NULL || size == 0)
	return (-1);

printf("Searching in array: ");
for (i = 0; i < size; i++)
{
	printf("%d", array[i]);
	if (i < size - 1)
		printf(", ");
}
printf("\n");

mid = (size - 1) / 2;
if (array[mid] == value)
{
	if (size == 1 || (array[mid - 1] < value))
		return (mid);
}

if (array[mid] < value)
{
	ret = advanced_binary(array + mid + 1, size - mid - 1, value);
	if (ret != -1)
		return (ret + mid + 1);
}
else
{
	ret = advanced_binary(array, mid + 1, value);
	if (ret != -1)
		return (ret);
}
return (-1);
}
