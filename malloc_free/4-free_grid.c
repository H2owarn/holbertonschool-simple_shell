#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * free_grid - frees a 2 dimensional grid previously
 *
 * @grid: 
 * @height: 
 *
 * Return: 
 */
void free_grid(int **grid, int height)
{
	int i;
	for (i = 0; i < height; i = i + 1)
	{
		free(grid[i]);
	}
	free(grid);
}
