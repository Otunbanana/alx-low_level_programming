#include "main.h"
#include <stdio.h>
/**
* print_diagsums - locates a substring
* @a: array
* @size: size
*/

void print_diagsums(int *a, int size)
{
int i, j, sum1 = 0, sum2 = 0;

for (i = 0; i < size; i++)
{
sum1 += *(a + i * size + i);
}

for (i = 0, j = size - 1; i < size; i++, j--)
{
sum2 += *(a + i * size + j);
}

printf("Diagonal sum 1: %d\n", sum1);
printf("Diagonal sum 2: %d\n", sum2);
}
