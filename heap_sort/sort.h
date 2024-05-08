#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap(int* a, int* b);
void heapify(int arr[], int n, int i);


#endif /* _SORT_H_ */