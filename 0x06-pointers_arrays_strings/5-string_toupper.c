#include "main.h"
#include <ctype.h>

/**
* string_toupper - Changes all lowercase letters to uppercase
* @p: The string will be modified
*
* Return: char var
*/

char *string_toupper(char *p)
{
for (int i = 0; p[i]; i++)
{
p[i] = toupper(p[i]);
}

return (p);
}

