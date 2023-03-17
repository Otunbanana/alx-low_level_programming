#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
* *_realloc - reallocates a memory block
* @ptr: pointer to old memory
* @old_size: old size
* @new_size: new size
*
* Return: Always 0.
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *new_ptr;
if (new_size == 0)
{
free(ptr);
return (NULL);
}

if (ptr == NULL)
{
return (malloc(new_size));
}

if (new_size == old_size)
{
return (ptr);
}

new_ptr = malloc(new_size);

if (new_ptr != NULL)
{
memcpy(new_ptr, ptr, (new_size < old_size) ? new_size : old_size);
free(ptr);
}

return (new_ptr);
}
