#include "main.h"
/**
* _memcpy -  copies memory area.
* @dest: destination array
* @src: source array
* @n: n bytes to copy
* Return: s
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
char *dest_ptr = dest;
char *src_ptr = src;
unsigned int i;

for (i = 0; i < n; i++)
{
*dest_ptr++ = *src_ptr++;
}

return (dest);
}
