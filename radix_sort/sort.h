#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
void countSort(int array[], size_t size, int exp);
int getMax(int array[], size_t size);


#endif /* _SORT_H_ */
