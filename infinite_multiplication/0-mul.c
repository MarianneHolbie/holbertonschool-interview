#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"


/**
 * print_error - prints "Error" and exits with status 98
*/
void print_error(void)
{
char *error = "Error\n";
while (*error)
{
_putchar(*error);
error++;
}
exit(98);
}

/**
 * _isdigit - check if a string contains only digits
 * @str: string to check
*/
void _isdigit(char *str)
{
int i;

for (i = 0; str[i]; i++)
{
if (!(str[i] >= '0' && str[i] <= '9'))
print_error();
}
}


/**
 * _strlen - return length of string
 * @str: string to check
 * Return: length of string
*/
int _strlen(char *str)
{
int len = 0;
while (str[len])
len++;
return (len);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of argument
 * @argv: arguments
 * Return: 0 on success, or 98 on failure
*/
int main(int argc, char *argv[])
{
int len1, len2;
int *result;
int i, j, sum, mul;

if (argc != 3)
print_error();
_isdigit(argv[1]);
_isdigit(argv[2]);
len1 = _strlen(argv[1]);
len2 = _strlen(argv[2]);
result = malloc((len1 + len2) *sizeof(int));
if (!result)
print_error();

for (i = 0; i < len1 + len2; i++)
result[i] = 0;
for (i = len1 - 1; i >= 0; i--)
{
for (j = len2 - 1; j >= 0; j--)
{
mul = (argv[1][i] - '0') * (argv[2][j] - '0');
sum = mul + result[i + j + 1];
result[i + j + 1] = sum % 10;
result[i + j] += sum / 10;
}
}

i = 0;
while (i < len1 + len2 && result[i] == 0)
i++;
if (i == len1 + len2)
_putchar('0');
else
while (i < len1 + len2)
{
_putchar(result[i] + '0');
i++;
}
_putchar('\n');
return (0);
}
