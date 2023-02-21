#include "main.h"

/**
 * print_last_digit - print last digit of integer
 * @n: integer argument
 * Return: last digit of number
 */

int print_last_digit(int n)
{
int nv;

if (n < 0)
{
nv = -1 * (n % 10);
_putchar(nv + '0');
return (nv);
}
else
{
nv = n % 10;
_putchar(nv + '0');
return (nv);
}
}
