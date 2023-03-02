#include "main.h"
/**
* _strcmp - Compares two strings
* @s1: The first string
* @s2: The second string
*
* Return: int value
*/

int _strcmp(const char *s1, const char *s2)
{
int i;
for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
{
if (s1[i] < s2[i])
{
return -1;
}
else if (s1[i] > s2[i])
{
return 1;
}
}
if (s1[i] == '\0' && s2[i] == '\0')
{
return 0;
}
else if (s1[i] == '\0')
{
return -1;
}
else
{
return 1;
}
}
