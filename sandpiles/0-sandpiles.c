#include "sandpiles.h"
#include <stdbool.h>

/**
 * is_stable - check if the sandpile is stable
 * @grid: sandpile to check, size[3][3]
 * Return: True or False
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (false);
			}
		}
	}
	return (true);
}

/**
 * topple - topple the sandpile at the given coordinates
 * @grid: sandpile
 */
void topple(int grid[3][3])
{
	int i, j;
	int tmp[3][3];

	/* cells need topple */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				tmp[i][j] = 1;
				grid[i][j] -= 4;
				/* TOP topple */
				if (i > 0)
					grid[i - 1][j]++;
				/* BOTTOM topple */
				if (i < 2)
					grid[i + 1][j]++;
				/* LEFT topple */
				if (j > 0)
					grid[i][j - 1]++;
				/* RIGHT topple */
				if (j < 2)
					grid[i][j + 1]++;
			}
		}
	}
}

/**
 * sandpiles_sum- sandpile addition
 * @grid1 : first sandpile
 * @grid2: second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	/* Add sandpiles */
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* toppling until stable */
	while (!is_stable(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}

/**
 * print_grid- print grid
 * @grid: grid[3][3] to print
 * Return: printed grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

