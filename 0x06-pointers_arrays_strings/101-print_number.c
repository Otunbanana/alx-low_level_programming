#include "main.h"

/**
* print_number - Prints an integer using _putchar function
* @n: The integer to print
*/
void print_number(int n)
{
int digits = 0, divisor = 1;

if (n < 0)
{
_putchar('-');
n *= -1;
}

while (n / divisor > 9)
divisor *= 10;

do {
_putchar(n / divisor + '0');
digits++;
divisor /= 10;
} while (divisor != 0 || digits == 0);
}
