#include "main.h"
#include <stdlib.h>

/**
* free_grid - frees a 2 dimensional grid
* @grid: previously created by your alloc_grid
* @height: height
*
* Return: Always zero
*/

void free_grid(int **grid, int height)
{
int i;
for (i = 0; i < height; i++)
{
free(grid[i]);
}

free(grid);
}
