#include "main.h"

/**
* get_endianness - checks the endianness.
* Return: void.
*/

int get_endianness(void)
{
int i;
char *c;
i = 1;
c = (char *)&i;

if (*c == i)
{
return (1); /* little endian */
}
else
{
return (0); /* big endian */
}
}
