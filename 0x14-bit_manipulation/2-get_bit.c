#include "main.h"

/**
* get_bit - Returns the value of a bit at a given index.
* @n: The number to get the bit from.
* @index: The index of the bit to get, starting from 0.
*
* Return: The value of the bit at index 'index' or -1 if an error occured.
*/
/* How far KImba */
int get_bit(unsigned long int n, unsigned int index)
{
if (index >= (sizeof(unsigned long int) * 8)) /* Ensure valid index */
return (-1);

/* Shift n 'index' bits to the right and check the bit at new 0th position */
return ((n >> index) & 1);
}
