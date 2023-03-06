#include "main.h"

/**
* _memset - fills memory with a constant byte.
* @s: input array
* @b: constant
* @n: n bytes to fill
* Return: s
*/

char *_memset(char *s, char b, unsigned int n) {
char *ptr = s;
while (n--) {
*ptr++ = b;
}
return s;
}
