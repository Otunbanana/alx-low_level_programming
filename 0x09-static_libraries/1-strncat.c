#include "main.h"
#include <stddef.h>
#include <string.h>
/**
 * _strncat - concatenates two strings n bytes from src
 * @dest: The destination value
 * @src: The source value
 * @n: The limit of the concatenation
 *
 * Return: char.
 */

char *_strncat(char *dest, char *src, int n)
{
char *d = dest;
const char *s = src;
size_t len = strlen(dest);

dest += len;

while (n-- > 0 && *s)
{
*dest++ = *s++;
}

*dest = '\0';

return (d);
}
