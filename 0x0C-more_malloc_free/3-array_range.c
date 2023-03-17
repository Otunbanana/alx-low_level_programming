#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
* *array_range - creates an array of integers
* @min: minimum array
* @max: maximum array
*
* Return: Always 0.
*/

int *array_range(int min, int max)
{
int *array;
int i;
if (min > max)
{
return (NULL);
}

array = malloc((max - min + 1) * sizeof(int));
if (array == NULL)
{
return (NULL);
}

for (i = 0; i <= (max - min); i++)
{
array[i] = min + i;
}

return (array);
}
