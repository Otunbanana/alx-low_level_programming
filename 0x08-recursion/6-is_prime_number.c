#include "main.h"
/**
* is_prime_helper - returns 1 if the input integer is a prime
* @n: base number
* @i: current value of i being checked
* Return: boolean
**/

int is_prime_helper(int n, int i)
{
if (n <= 1)
{
return (0);
}
else if (i * i > n)
{
return (1);
}
else if (n % i == 0)
{
return (0);
}
else
{
return is_prime_helper(n, i + 1);
}
}

/**
* is_prime_number - returns 1 if the input integer is a prime
* @n: base number
* Return: boolean
**/
int is_prime_number(int n)
{
return is_prime_helper(n, 2);
}
