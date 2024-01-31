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
 * @i: row
 * @j: column
 */
void topple(int grid[3][3], int i, int j)
{
	int tmp[3][3];
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			tmp[x][y] = grid[x][y];
		}
	}
	tmp[i][j] -= 4;

	/* BOTTOM topple */
	if (i + 1 < 3)
	{
		tmp[i + 1][j]++;
	}
	/* TOP topple */
	if (i - 1 >= 0)
	{
		tmp[i - 1][j]++;
	}
	/* RIGHT topple */
	if (j + 1 < 3)
	{
		tmp[i][j + 1]++;
	}
	/* LEFT topple */
	if (j - 1 >= 0)
	{
		tmp[i][j - 1]++;
	}
	/* copy tmp to original grid */
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid[x][y] = tmp[x][y];
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

	do {
		printf("=\n");
		print_grid(grid1);

		for (i = 0; i < 3; ++i)
		{
			for (j = 0; j < 3; ++j)
			{
				if (grid1[i][j] > 3)
				{
					topple(grid1, i, j);
				}
			}
		}

	/* topple until stable */
	} while (!is_stable(grid1));
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

