#include "main.h"

/**
* set_bit - Sets the value of a bit to 1 at a given index
* @n: Pointer to the unsigned long int to modify
* @index: Index, starting from 0, of the bit to set
*
* Return: 1 if it worked, or -1 if an error occurred
*/

/* kimbi kimba, nothing to see here */
int set_bit(unsigned long int *n, unsigned int index)
{
unsigned long int mask = 1;

if (index > (sizeof(unsigned long int) * 8 - 1))
return (-1);

mask <<= index;
*n |= mask;

return (1);
}
