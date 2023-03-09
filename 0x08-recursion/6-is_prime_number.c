#include "main.h"
/**
* prime - returns 1 if the input integer is a prime
* @n: base number
* Return: boolean
**/

int is_prime_number(int n)
{
if (n <= 1)
{
return (0);
}
int i;
for (i = 2; i * i <= n; i++)
{
if (n % i == 0)
{
return (0);
}
}
return (1);
}
