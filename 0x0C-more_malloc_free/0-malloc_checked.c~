#include <stdlib.h>
#include <stdio.h>
/**
* *malloc_checked - allocates memory using malloc
* @b: integer to assign memory to 
*
* Return: 98
*/

void *malloc_checked(unsigned int b)
{
void *ptr = malloc(b);
if (ptr == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(98);
}
return ptr;
}
