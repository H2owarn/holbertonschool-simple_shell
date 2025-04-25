#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * alloc_grid - returns a pointer to a 2 dimensional array
 *
 * @width : number
 * @height : number
 *
 * Return: 2 dimensional array
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);
	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);
	for (i = 0; i < height; i = i + 1)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			while (i > 0)
			{
				free(grid[i - 1]);
				i = i - 1;
			}
			free(grid);
			return (NULL);
		}
		for (j = 0; j < width; j = j + 1)
			grid[i][j] = 0;
	}
	return (grid);
}
