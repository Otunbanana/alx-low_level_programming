#include "function_pointers.h"
#include <stdio.h>
/**
* print_name - print name
* @name: name to print
* @f: function of name
*
* Return: void.
*/
void print_name(char *name, void (*f)(char *))
{
if (name != NULL && f != NULL)
f(name);
}
