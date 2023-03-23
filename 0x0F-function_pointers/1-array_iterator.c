#include "function_pointers.h"


/**
* array_iterator - executes a function given as a parameter
*
* @array: array to execute
* @size: is the size of array
* @action:  pointer to the function
*
* Return: void
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
size_t i;


if (array && action)
{
i = 0;
while (i < size)
{
action(array[i]);
i++;
}
}
}

