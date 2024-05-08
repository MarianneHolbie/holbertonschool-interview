#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * heapify - create heap from array
 * @arr: Array
 * @n: Size
 * @i: Index
 */
void heapify(int arr[], int n, int i)
{
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;

if (left < n && arr[left] > arr[largest])
	largest = left;

if (right < n && arr[right] > arr[largest])
	largest = right;

if (largest != i)
{
	swap(&arr[i], &arr[largest]);
	heapify(arr, n, largest);
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
 * @n: Size
*/
void heap_sort(int arr[], size_t n)
{
	/* rearrange array */
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	/* extract elements from heap */
	for (int i = n - 1; i >= 0; i--)
	{
		print_array(arr, n);

		/* move current root to end */
		swap(&arr[0], &arr[i]);

		/* call max heapify on the reduced heap */
		heapify(arr, i, 0);
	}
}

