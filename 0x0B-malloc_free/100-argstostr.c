#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
* *argstostr - concatenates all the arguments of your program
* @ac: arguments count
* @av: argument
*
* Return: Always zero
*/

char *argstostr(int ac, char **av)
{
int total_length;
int i;
int offset;
int length;
char *str;

if (ac == 0 || av == NULL)
{
return (NULL);
}

total_length = 0;
for (i = 0; i < ac; i++)
{
total_length += strlen(av[i]) + 2;
}

str = malloc(total_length * (sizeof(char)));
if (str == NULL)
{
return (NULL);
}

offset = 0;
for (i = 0; i < ac; i++)
{
length = strlen(av[i]);
memcpy(str + offset, av[i], length);
str[offset + length] = '\n';
offset += length + 1;
}

str[total_length - 1] = '\0';

return (str);
}
