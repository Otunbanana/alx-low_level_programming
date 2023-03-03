#include "main.h"

/**
* print_number - Prints an integer using _putchar function
* @n: The integer to print
*/
void print_number(int n)
{
unsigned int number;

number = n;
if (n < 0)
{
_putchar(45);
number = -n;
}

if (number / 10 != 0)
print_number(number / 10);

_putchar(number % 10 + '0');
}
