#include "main.h"

/**
* swap_int - swap the value of a to b and b to a
*@a: pointer to a
*@b: pointer to b
*
* Return: void.
*/

void swap_int(int *a, int *b)
{
int ahold = *a;
*a = *b;
*b = ahold;
}
