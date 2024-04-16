# Linear Search in Skip List
This script implements a linear search algorithm in a skip list data structure. The skip list is a linked list with an "express lane" that allows for faster searching of elements.


# Compilation
To compile the program, use the following command: `gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c skiplist/*.c -o 0-linear_skip`
Code for `0-main.c`
```
#include <stdio.h>
#include <stdlib.h>

#include "search.h"

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    skiplist_t *list, *res;
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    list = create_skiplist(array, size);
    print_skiplist(list);

    res =  linear_skip(list, 53);
    printf("Found %d at index: %lu\n\n", 53, res->index);
    res =  linear_skip(list, 2);
    printf("Found %d at index: %lu\n\n", 2, res->index);
    res =  linear_skip(list, 999);
    printf("Found %d at index: %p\n", 999, (void *) res);

    free_skiplist(list);
    return (EXIT_SUCCESS);
}
```

# Use
After compilation, run the program with `./0-linear_skip`.
It will output the results of the search for specific values in the skip list.


# Include accessory function
Retrieve the skiplist directory from `https://github.com/hs-hq/0x0E.Linear_search-in_skip_list/tree/main`
Don't forget to use search.h.
