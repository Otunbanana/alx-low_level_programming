#include "main.h"
/**
* _strncpy - Copy a string
* @dest: The destination value
* @src: The source value
* @n: The copy limit
*
* Return: char value
*/

char *_strncpy(char *dest, const char *src, size_t n)
{
char *d = dest;

while (n-- > 0 && *src)
{
*dest++ = *src++;
}

while (n-- > 0)
{
*dest++ = '\0';
}

return (d);
}
