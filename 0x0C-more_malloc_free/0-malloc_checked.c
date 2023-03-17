#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
* *malloc_checked - allocates memory using malloc
* @b: integer to assign memory to
*
* Return: ptr
*/

void *malloc_checked(unsigned int b)
{
void *ptr = malloc(b);
if (ptr == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(98);
}
return (ptr);
}
