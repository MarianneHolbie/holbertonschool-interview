#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * heapify - create heap from array
 * @arr: Array
 * @size: Size
 * @calcsize: Size
 * @i: Index
 */
void heapify(int arr[], size_t size, size_t calcsize, int i)
{
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
int n = (int)size;

if (left < n && arr[left] > arr[largest])
	largest = left;

if (right < n && arr[right] > arr[largest])
	largest = right;

if (largest != i)
{
	swap(&arr[i], &arr[largest]);
	print_array(arr, calcsize);
	heapify(arr, n, calcsize, largest);
}
}

/**
 * swap - swap 2 elements of an array
 * @a: element 1
 * @b: element 2
*/
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * heap_sort - sort an array of integers in ascending
 * order using the Heap sort algorithm
 * @arr: Array
 * @size: Size
*/
void heap_sort(int arr[], size_t size)
{
	int i;

	/* rearrange array */
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, size, i);

	/* extract elements from heap */
	for (i = size - 1; i > 0; i--)
	{
		/* move current root to end */
		swap(&arr[0], &arr[i]);

		print_array(arr, size);

		/* call max heapify on the reduced heap */
		heapify(arr, i, size, 0);
	}
}
