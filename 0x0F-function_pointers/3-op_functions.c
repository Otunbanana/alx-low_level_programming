#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>


/**
* op_add - add operator
* @a: first input
* @b: second input
*
* Return: return 0
*/
int op_add(int a, int b)
{
return (a + b);
}


/**
* op_sub - subtract operator
* @a: first input
* @b: second input
*
* Return: return 0
*/
int op_sub(int a, int b)
{
return (a - b);
}


/**
* op_mul - minus operator
* @a: first input
* @b: second input
*
* Return: return 0
*/
int op_mul(int a, int b)
{
return (a * b);
}


/**
* op_div - divide operator
* @a: first input
* @b: second input
*
* Return: return 0
*/
int op_div(int a, int b)
{
if (b == 0)
{
printf("Error\n");
exit(100);
}


return (a / b);
}


/**
* op_mod - modulo operator
* @a: first input
* @b: second input
*
* Return: return 0
*/
int op_mod(int a, int b)
{
if (b == 0)
{
printf("Error\n");
exit(100);
}


return (a % b);
}

