#include "main.h"

/**
* flip_bits - Returns the number of bits you would need to flip to
* get from one number to another.
* @n: First number.
* @m: Second number.
* Return: Number of bits needed to flip.
*/
/* Hey kimbs, another one */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int xor_result = n ^ m;
unsigned int flip_count = 0;

while (xor_result)
{
if (xor_result & 1)
flip_count++;
xor_result >>= 1;
}

return (flip_count);
}
