# String Comparison with Wildcards

This project implements a function that compares two strings, with support for wildcard characters.

## Function Prototype

```c
int wildcmp(char *s1, char *s2);
```

## Description

The `wildcmp` function compares two strings: `s1` and `s2`. It returns 1 if the strings can be considered identical, otherwise it returns 0.

The second string (`s2`) can contain the special character `*`. This wildcard character can replace any string (including an empty string).

## Usage

To use this function, include the `holberton.h` header file in your C program and call the `wildcmp` function with two string arguments.

Example:

```c
#include "holberton.h"
#include <stdio.h>

int main(void)
{
    printf("%d\n", wildcmp("main.c", "*.c")); // Should print 1
    printf("%d\n", wildcmp("main.c", "m*a*i*n*.*c*")); // Should print 1
    printf("%d\n", wildcmp("main.c", "main.cpp")); // Should print 0
    return (0);
}
```

## Compilation

Compile your program with the following command:

```
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o wildcmp
```

## Note

This implementation uses recursion to handle the wildcard comparisons. Be mindful of potential stack overflow for very long strings or patterns with many wildcards.