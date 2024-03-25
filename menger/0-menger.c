#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"

/**
 * position_character- determines wether to print '#' or ' ' at a giver
 * postion
 * @row: row index
 * @col: col index
 * @size: size of the current Menger sponge level
 *
 * Return: '#' or ' '
 */

char position_character(int row, int col, int size)
{
	while (size > 3)
	{
		if ((row % 3) == 1 && (col % 3) == 1)
			return (' ');
		row /= 3;
		col /= 3;
		size /= 3;
	}

	if (size == 3 && (row == 1 && col == 1))
		return (' ');

	return ('#');
}

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 */

void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = pow(3, level);

	for (row = 0; row < size; ++row)
	{
		for (col = 0; col < size; ++col)
			putchar(position_character(row, col, size));
		putchar('\n');
	}
}

