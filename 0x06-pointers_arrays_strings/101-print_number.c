#include "main.h"

/**
* print_number - prints an integer
* @n: the integer to print
*/

void print_number(int n)
{
int num_digits = 0;
int temp = n;
if (n < 0)
{
_putchar('-');
temp = -n;
}
while (temp != 0)
{
num_digits++;
temp /= 10;
}
while (num_digits > 0)
{
int divisor = 1;
for (int i = 1; i < num_digits; i++)
{
divisor *= 10;
}
int digit = n / divisor;
_putchar(digit + '0');
n %= divisor;
num_digits--;
}
if (n == 0)
{
_putchar('0');
}
}
