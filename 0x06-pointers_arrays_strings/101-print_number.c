#include "main.h"

/**
* print_number - Prints an integer using _putchar function
* @n: The integer to print
*/
void print_number(int n)
{
if (n < 0)
{
_putchar(45);
n *= -1;
}

if (n / 10 != 0)
print_number(n / 10);

_putchar(n % 10 + '0');
}
