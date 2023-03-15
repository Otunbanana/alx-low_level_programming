#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
* argstostr - concatenates all the arguments of your program
* @ac: arguments count
* @av: argument
*
* Return: pointer to a new string or NULL if it fails
*/
char *argstostr(int ac, char **av)
{
int total_length = 0;
char *str;
int i, j, k;

if (ac == 0 || av == NULL)
return (NULL);

for (i = 0; i < ac; i++)
total_length += strlen(av[i]) + 1;

str = malloc(total_length + 1);
if (str == NULL)
return (NULL);

k = 0;
for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j] != '\0'; j++, k++)
str[k] = av[i][j];
str[k++] = '\n';
}
str[k] = '\0';

return (str);
}
